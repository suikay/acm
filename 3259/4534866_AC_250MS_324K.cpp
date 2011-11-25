#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#define INFINITY 999999999
using namespace std;
//用于储存边
typedef struct {
	int w;
	int v;
	int weight;
}Edge;
Edge edge[5500];
int d[1000];
//我的Bellman-Ford标程
bool BF(int n,int path)
{
	for(int i = 1; i <= n; i++)
		d[i] = INFINITY;
	d[1] = 0;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < path; j++)
			if(d[edge[j].w] + edge[j].weight < d[edge[j].v])
				d[edge[j].v] = d[edge[j].w] + edge[j].weight;
	//如果有负权环则返回false
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
		for(int j = 0; j < 2 * m; j+=2)  {
			cin >> x >> y >> xy;
			//由于path是无向边所以要加一条反向的
			edge[j].w = edge[j+1].v = x;
			edge[j].v = edge[j+1].w = y;
			edge[j].weight = edge[j+1].weight = xy;
		}
		for(int j = 0; j < w; j++) {
			cin >> edge[j + 2*m].w >> edge[j + 2*m].v;
			cin >> xy;
			edge[j + 2*m].weight = -xy;
		}
		// 总路径数为 2*PATH + WORM
		if(!BF(n,2*m + w))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}