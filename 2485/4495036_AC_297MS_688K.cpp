#include <stdio.h>
#include <stdlib.h>
typedef struct Edge{
	int x;
	int y;
	int weigh;
}Edge;
Edge edge[251001];
int parent[501];
int compare(const void*a,const void *b)
{
	return ((Edge*)a)->weigh - ((Edge*)b)->weigh;
}
int FindParent(int x)
{
	if( parent[x] != x)
		parent[x] = FindParent(parent[x]);
	else
		return x;
	return parent[x];
}
void MergeSet(int x,int y)
{
	x = FindParent(x);
	y = FindParent(y);
	if( x > y)
		parent[y] = x;
	else
		parent[x] = y;
}
int main()
{
	int m,n;
	int count = 0;
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		scanf("%d",&m);
		for( int j = 0; j < m; j++)
			parent[j] = j;
		for( int j = 0; j < m; j++)
			for( int k = 0; k < m; k++) {
				scanf("%d",&edge[count].weigh);
				edge[count].x = j;
				edge[count++].y = k;
			}
		qsort(edge,m * m,sizeof(Edge),compare);
		count = 1;
		int max;
		for( int j = m; j < (m * m) && count < m; j++)
			if(FindParent(edge[j].x) != FindParent(edge[j].y)) {
				count ++;
				MergeSet(edge[j].x,edge[j].y);
				max = edge[j].weigh;
			}
		printf("%d\n",max);
	}
}