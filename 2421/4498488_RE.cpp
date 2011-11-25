#include <stdio.h>
#include <stdlib.h>
typedef struct Edge
{
	int x;
	int y;
	int lenght;
}Edge;
Edge edge[5000];
int parent[101];
int compare(const void* a,const void* b)
{
	return ((Edge*)a)->lenght - ((Edge*)b)->lenght;
}
int FindParent(int x)
{
	if(parent[x]) {
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
	else
		return x;
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
	char s[100];
	int n,count = 0,lenght,max;
	int x,y;
	scanf("%d\n",&n);
	for( int i = 1; i <= n; i++) {
		for(int j = 1; j < i;j++) {
			scanf("%d",&lenght);
			edge[count].x = i;
			edge[count].y = j;
			edge[count].lenght = lenght;
			count++;
		}
		gets(s);
	}
	qsort(edge,count,sizeof(Edge),compare);
	count = n - 1;
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		scanf("%d%d",&x,&y);
		MergeSet(x,y);
		count--;
	}
	for( int i = 0; count; i++) 
		if(FindParent(edge[i].x) != FindParent(edge[i].y)) {
			MergeSet(edge[i].x,edge[i].y);
			count--;
			max = edge[i].lenght;
		}
	printf("%d\n",max);
}