#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct Point{
	short left;
	short right;
	bool operator()(Point a,Point b) {
		return( a.left == b.left ?a.right < b.right:a.left< b.left);
	}
}Point;
Point *point;
int main()
{
	int n;
	scanf("%d",&n);
	point = new Point[n];
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&point[i].left,&point[i].right);
		if(point[i].left > point[i].right) {
			int temp = point[i].left;
			point[i].left = point[i].right;
			point[i].right = temp;
		}
	}
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
			l = (r > point[i].right - 1) ?point[i].right - 1:r; 
			r = point[i].right;
			count++;
			continue;
		}
		if(r > point[i].right)
			r = point[i].right;
		}
	printf("%d\n",count);
}
