#include <memory.h>
#include <iostream>
#define INFINITY 94967295
using namespace std;
unsigned int road[101][101];
void ShortestPatch_FLOYD(int n) {
	bool p[101][101][101];
	int v,w,u;
	for(v = 1; v <= n;v++) 
		for(w = 1; w <= n; w++) {
			for(u = 1; u <= n; u++)
				p[v][w][u] = false;
			if(road[v][w] < INFINITY )
				p[v][w][v] = p[v][w][w] = true;
		}
	for( u = 1; u <= n; u++)
		for( v = 1; v <= n; v++)
			for( w = 1; w <= n; w++)
				if(road[v][u] + road[u][w] < road[v][w])  {
					road[v][w] = road[v][u] + road[u][w];
					for( int i = 1; i <= n; i++)
						p[v][w][i] = p[v][u][i] || p[u][w][i];
				}
}
int main()
{
	int n, m, o;
	while( cin >> n && n) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				road[i][j] = INFINITY;
		for(int i = 1; i <= n; i++)  {
			cin >> m;
			for(int j = 1;  j <= m; j++) {
				cin >> o;
				cin >> road[i][o];
			}
		}
		ShortestPatch_FLOYD(n);
		unsigned int min = INFINITY,mink;
		for(int i = 1; i <= n; i++) {
			road[i][0] = 0;
			for(int j = 1; j <= n; j++) 
				if( i != j )
					if(road[i][j] == INFINITY ) {
						road[i][0] = INFINITY;
						break;
					}
					else
						road[i][0] = (road[i][0] < road[i][j] )?road[i][j]:road[i][0];
			if(road[i][0] < min) {
				min = road[i][0];
				mink = i;
			}
		}
		if(min < INFINITY)
			cout << mink << " " << min << endl;
		else
			cout << "disjoint" << endl;
	}
}