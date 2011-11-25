//这段代码用Kruskal来解决

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;
// 边类型
typedef struct Edge{
	int x;
	int y;
	int weigh;
	bool operator() ( Edge a,Edge b) {
		return (a.weigh < b.weigh);
	}
}Edge;
//最多可能的边
Edge edge[251001];
int parent[501];
//用于qsort()的比较函数
int compare(const void*a,const void *b)
{
	return ((Edge*)a)->weigh - ((Edge*)b)->weigh;
}
// 找父节点并压缩路径
int Find(int x)
{
	if( parent[x] >= 0)
		parent[x] = Find(parent[x]);
	else
		return x;
	return parent[x];
}
// 合并集合
void Union(int x,int y)
{
	x = Find(x);
	y = Find(y);
	// 注意:这里的重边判断很重要
	if( x == y)
		return ;
	if(parent[x] < parent[y]) 
		parent[y] = x;
	else
		if(parent[x] > parent[y])
			parent[x] = y;
		else {
			parent[x]--;
			parent[y] = x;
		}
}
int main()
{
	int m,n;
	int count = 0;
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		scanf("%d",&m);
		memset(parent,-1,m * sizeof(int));
		for( int j = 0; j < m; j++)
			for( int k = 0; k < m; k++) {
				scanf("%d",&edge[count].weigh);
				edge[count].x = j;
				edge[count++].y = k;
			}
		sort(edge,edge + m * m,Edge());
		count = 1;
		int max;
		// 忽略那些为0的节点,有m个,然后从小到大去边
		for( int j = m; j < (m * m) && count < m; j++)
			if(Find(edge[j].x) != Find(edge[j].y)) {
				count ++;
				Union(edge[j].x,edge[j].y);
				max = edge[j].weigh;
			}
		printf("%d\n",max);
	}
}