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
Point point[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&point[i].left,&point[i].right);
		// 因为
		if(point[i].left > point[i].right) {
			int temp = point[i].left;
			point[i].left = point[i].right;
			point[i].right = temp;
		}
	}
	// 对数组排序以进行贪心
	sort(point,point+n,Point());
	int count = 2;
	// l 储存现有的左指针,r储存右指针
	int l,r;
	r = point[0].right;
	l = r - 1;
	for(int i = 1; i < n; i++) {
		// 如果 r 比这个点的左节点还小的话
		// 意味着它们没有重叠的地方
		if(point[i].left > r) {
			count += 2;
			r = point[i].right;
			l = r - 1;
			continue;
		}
		if(l < point[i].left) {
			// !!! 下面这一句灰常重要 看图
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
