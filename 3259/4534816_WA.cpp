#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#define INFINITY 999999999
using namespace std;
typedef struct {
	int w;
	int v;
	int weight;
}Edge;
Edge edge[3000];
int d[1000];
bool BF(int n,int path)
{
	for(int i = 0; i <= n; i++)
		d[i] = INFINITY;
	d[1] = 0;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < path; j++)
			if(d[edge[j].w] + edge[j].weight < d[edge[j].v])
				d[edge[j].v] = d[edge[j].w] + edge[j].weight;
	for(int j = 0; j < path; j++)
		if(d[edge[j].w] + edge[j].weight < d[edge[j].v])
			return false;
	return true;
}
int main()
{
	int time, n, m, w;
	int x,y,xy;
	cin >> time;
	for(int i = 0; i < time; i++) 
	{	
		cin >> n >> m >> w;
		for(int j = 0; j < m; j++) 
			cin >> edge[j].w >>edge[j].v >>	edge[j].weight ;
		for(int j = 0; j < w; j++) {
			cin >> edge[j + m].w >> edge[j + m].v;
			cin >> xy;
			edge[j + m].weight = -xy;
		}
		BF(n,m + w);
		if(d[1] < 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}