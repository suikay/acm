#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
using namespace std;
typedef struct Edge{
	int x;
	int y;
	int weigh;
}Edge;
Edge edge[1000];
int parent[100];
int FindParent(int x)
{
	if(parent[x])
		parent[x] = FindParent(parent[x]);
	else
		return x;
	return parent[x];
}
void MergeSet(int x, int y)
{
	int t1 = FindParent(x);
	int t2 = FindParent(y);
	if( t1 > t2)
		parent[t2] = t1;
	else
		parent[t1] = t2;
}
int compare(const void* a,const void* b)
{
	return ((Edge*)a)->weigh - ((Edge*)b)->weigh;
}
int main()
{
	int n, count;
	char x,y;
	int v, weigh, sum;
	cin >> n;
	while( n) {
		getchar();
		count = sum = 0;
		for( int i = 0; i < n - 1; i++) {
			cin >> x >> v;
			x = x - 'A' + 1;
			for( int j = 0; j < v; j++) {
				cin >> y >>weigh;
				y = y - 'A' + 1;
				edge[count].x = x;
				edge[count].y = y;
				edge[count++].weigh = weigh;
			}
			getchar();
		}
		qsort(edge,count,sizeof(Edge),compare);
		memset(parent,0,27 * sizeof(int));
		for(int i = 0; i < count; i++)
			if(FindParent(edge[i].x) != FindParent(edge[i].y)) {
				sum += edge[i].weigh;
				MergeSet(edge[i].x,edge[i].y);
			}
		cout << sum << endl;
		cin >> n;
	}
}
