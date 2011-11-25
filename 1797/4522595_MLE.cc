#include <memory.h>
#include <iostream>
#define INFINITY 994967295
#define min(x,y) (x) > (y) ?( y):(x);
using namespace std;
unsigned int road[1001][1001];
bool p[1001][1001][1001];
//最短路径的弗洛伊德
void ShortestPatch_FLOYD(int n) {
	int v,w,u;
	for(v = 1; v <= n;v++) 
		for(w = 1; w <= n; w++) {
			for(u = 1; u <= n; u++)
				p[v][w][u] = false;
			if(road[v][w] )
				p[v][w][v] = p[v][w][w] = true;
		}
	for( u = 1; u <= n; u++)
		for( v = 1; v <= n; v++)
			for( w = 1; w <= n; w++)
				if(!road[v][w] || (road[v][u] >road[v][w] && road[u][w] > road[v][w]))  {
					road[v][w] = min(road[v][u] , road[u][w]);
					for( int i = 1; i <= n; i++)
						p[v][w][i] = p[v][u][i] || p[u][w][i];
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
		ShortestPatch_FLOYD(n);
		unsigned int max = 0;
		/*
		for(int i = 1; i <= n; i++)
			if(road[i][n] > max )
				max = road[i][n];
				*/
			cout << "Scenario #" << count << ":" << endl << road[1][n] << endl;
	}
}