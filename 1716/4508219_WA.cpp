#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct Point{
	int left;
	int right;
	bool operator()(Point a,Point b) {
		return( a.left == b.left ?a.right < b.right:a.left< b.left);
	}
}Point;
Point point[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d%d",&point[i].left,&point[i].right);
	sort(point,point+n,Point());
	int count = 2;
	int l,r;
	r = point[0].right;
	l = r - 1;
	for(int i = 1; i < n; i++) {
		if(point[i].left > r) {
			count += 2;
			r = point[i].right;
			l = r - 1;
			continue;
		}
		if(l < point[i].left) {
			l = r;
			r = point[i].right;
			count++;
			continue;
		}
	}
	printf("%d\n",count);
}
