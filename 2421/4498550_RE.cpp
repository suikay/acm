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
Edge edge[10000];
int parent[110];
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
	int n,count ,lenght,sum;
	int x,y;
	int null;
	while(cin >> n) {
	count = 0;
	memset(parent,0,101*sizeof(int));
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
	count = n - 1;
	cin >> n;
	for( int i = 0; i < n; i++) {
		cin >> x >> y;
		MergeSet(x,y);
		count--;
	}
	sum = 0;
	for( int i = 0; count; i++) 
		if(FindParent(edge[i].x) != FindParent(edge[i].y)) {
			MergeSet(edge[i].x,edge[i].y);
			count--;
			sum += edge[i].lenght;
		}
	printf("%d\n",sum);
	}
}