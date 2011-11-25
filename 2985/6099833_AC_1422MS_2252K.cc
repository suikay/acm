#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define typev int
using namespace std;

const int N = 200010;
typev ar[N];
int lowb(int t) { return t & (-t); }
void add(int i) {
	for(; i < N; ar[i]++, i += lowb(i));
}
void del(int i) {
	for(; i < N; ar[i]--, i += lowb(i));
}
typev sum(int i) {
	typev s = 0;
	for(; i > 0; s += ar[i], i -= lowb(i));
	return s;
}

int parent[N];
int q[N],t;
int father(int x)
{
	////cout << " F " << endl;
	t = 0;
	while(parent[x] >= 0) {
		q[t] = x;
		x = parent[x];
	}
	for(int i = 0; i < t;i++)
		parent[q[i]] = x;
	return x;
}
bool merge(int x,int y)
{
	////cout << " M " << endl;
	static int xx,yy;
	xx = father(x);
	yy = father(y);
	if(xx == yy)
		return false;
	del(-parent[xx]); del(-parent[yy]);
	if(parent[xx] < parent[yy]) {
		parent[xx] += parent[yy];
		parent[yy] = xx;
		add(-parent[xx]);
	} else {
		parent[yy] += parent[xx];
		parent[xx] = yy;
		add(-parent[yy]);
	}
	return true;
}
int main()
{
	int m,n,cnt;
	int l,r,mid,k,p,x,y;
	scanf("%d%d",&m,&n);
	cnt = m;
	memset(ar,0,sizeof(ar));
	for(int i = 0 ;i < m; i++)
		add(1);
	memset(parent,-1,sizeof(parent));
	while(n--)
	{
		scanf("%d",&k);
		if(k == 1) {
			scanf("%d",&p);
			p = cnt-p+1;
			l = 1; r = m;
			while(l < r) {
				mid = (l+r) >> 1;
				//cout << l << " " << r <<  " " << sum(mid) << endl;
				if(sum(mid) < p)
					l = mid+1;
				else 
					r = mid;
			}
			printf("%d\n",l);
		} else {
			scanf("%d%d",&x,&y);
			if(merge(x,y))
				cnt--;
		}
	}

	return 0;
}
