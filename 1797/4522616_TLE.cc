#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;
unsigned int road[1001][1001];
unsigned int d[1001];
#define min(x,y) (x) > (y) ? (y):(x);
void ShortestPath_DIJ(int n)
{
	int v;
	bool final[1001];
	for(int i = 1; i <= n; i++) {
		final[i] = false;
		d[i] = road[1][i];
	}
	d[1] = 0; 
	final[1] = true;
	unsigned int max;
	for(int i = 1; i <= n; i++) {
		max = 0;
		for(int w = 1; w <= n; w ++)
			if(!final[w])
				if(d[w]  > max ) {
					v = w;
					max = d[w];
				}
		final[v] = true;
		for(int w = 1; w <= n; w++)
			if(!final[w] && ( road[1][w] < max && road[1][w] < road[v][w] )) 
				d[w] = min(road[v][w] , max);
	}
}

int main()
{
	
	int n, m;
	int x,y,time;
	cin >> time;
	for(int count = 1; count <= time; count++) {
		cin >> n >> m;
		memset(road,0,1001 * 1001 * sizeof(int));
			for(int j = 1;  j <= m; j++) {
				cin >> x >> y;
				cin >> road[x][y];
			}
		ShortestPath_DIJ(n);	
		cout << "Scenario #" << count << ":" << endl << d[n] << endl;
	}
}