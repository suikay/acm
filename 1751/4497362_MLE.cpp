#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define Lenght(i,j) (town[i].x - town[j].x) * (town[i].x - town[j].x) + (town[i].y - town[j].y) * (town[i].y - town[j].y)
#define N 751
typedef struct Town
{
	int x;
	int y;
}Town;
Town town[N];
typedef struct Edge 
{
	int x;
	int y;
	int lenght;
bool operator () ( const Edge &a, const Edge &b ) const 
{
	if(a.lenght < b.lenght)
		return true;
	return false;
}
} Edge;
Edge edge[ N * N / 2 + N];
int parent[N];
int FindParent(int x)
{
	if(parent[x]) {
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
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
	int n, count;
	count = 0;
	scanf("%d",&n);
	for ( int i = 1; i <= n; i++)
		scanf("%d%d",&town[i].x,&town[i].y);
	for( int i = 1; i < n; i++)
		for( int j = i + 1; j <= n; j++) {
			edge[count].x = i;
			edge[count].y = j;
			edge[count++].lenght = Lenght(i,j);
		}
	sort(edge,edge + count,Edge());
	int m,x,y;
	scanf("%d",&m);
	for( int i = 0; i < m; i ++) {
		scanf("%d%d",&x,&y);
		MergeSet(x,y);
	}
	for( int i = 0; i < count; i++)
		if( FindParent(edge[i].x) != FindParent(edge[i].y)) {
			printf("%d %d\n",edge[i].x,edge[i].y);
			MergeSet(edge[i].x,edge[i].y);
		}
}