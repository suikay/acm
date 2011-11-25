#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
#define N 1010
#define E 100100
int head[N], np[E], nxt[E], pn;
inline void addEdge(int x,int y)
{
	nxt[pn] = head[x]; np[pn] = y; head[x] = pn++;
}
int q[N], h, top;
int v[N];
int main()
{
	int n,k,x,y;
	memset(head,-1,sizeof(head));
	memset(v,0,sizeof(v));
	scanf("%d%d",&n,&k);
	pn = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		//addEdge(y,x);
	}
	top = h = 0;
	q[top++] = 1;
	v[1] = -1;
	int pp,ppp;
	while(h < top)
	{
		pp = q[h++];
		for(int i = head[pp];i != -1; i = nxt[i]) {
			ppp = np[i];
			//cout << pp << " " << ppp << " " << i << endl;
			if(v[ppp]) continue;
			v[ppp] = pp;
			if(ppp == k) {
				h = top;
				break;
			}
			q[top++] = ppp;
		}
	}
	pp = k;
	top = 0;
	if(!v[k]) {
		puts("-1");
		return 0;
	}
	while(pp > 0) {
		q[top++] = pp;
		pp = v[pp];
	}
	printf("%d\n",top);
	for(int i = top-1; i >= 0; i--)
		printf("%d\n",q[i]);

	return 0;
}
/*
6 5
1 3
3 2
2 3
3 1
5 4
2 1
2 5
*/
