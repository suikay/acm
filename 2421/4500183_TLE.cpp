#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Edge
{
	int x;
	int y;
	int lenght;
}Edge;
Edge edge[40000];
int parent[200];
int compare(const void* a,const void* b)
{
	return ((Edge*)a)->lenght - ((Edge*)b)->lenght;
}
int FindParent(int x)
{
	int px = x;
	while( parent[px] > 0) 
		px = parent[px];
	int temp;
	while(parent[x] > 0) {
		temp = parent[x];
		parent[x] = px;
		x = temp;
	}
	return px;
}
void MergeSet(int x,int y)
{
	x = FindParent(x);
	y = FindParent(y);
	if( parent[x] < parent[y])
		parent[y] = x;
	else
		if(parent[x] == parent[y]) {
			parent[y] = x;
			parent[x] -= 1;
		}
		else
			parent[x] = y;
}
int main()
{
	int n,count ,lenght;
	unsigned long long sum;
	int x,y,m;
	int null;
	cin >> n;
	count = 0;
	for( int i = 1; i <= n; i++) {
		for(int j = 1; j < i;j++) {
			cin >> lenght;
			edge[count].x = i;
			edge[count].y = j;
			edge[count].lenght = lenght;
			count++;
		}
		for(int j = i; j <= n;j++)
			cin >> null;
	}
	qsort(edge,count,sizeof(Edge),compare);
	cin >> m;
	for( int i = 0; i < m; i++) {
		cin >> x >> y;
		MergeSet(x,y);
	}
	sum = 0;
	for( int i = 0;i < count; i++) 
		if(FindParent(edge[i].x) != FindParent(edge[i].y)) {
			MergeSet(edge[i].x,edge[i].y);
			sum += edge[i].lenght;
		}
	cout << sum << endl;
}