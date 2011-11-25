#include <stdio.h>
#define MAX 1001
#define INFINITY 999999999
int road[MAX][MAX];
int D[MAX][MAX];
int n;
void Floyd()
{
	for(int i = 1;i <= n; i++)
		for(int w = 0; w <= n ;w++)
			D[i][w] = road[i][w];
	for(int u = 1; u <= n; u++)
		for(int v = 1; v <= n; v++)
			for(int w = 1; w <= n; w++)
				if(D[u][w] + D[v][u] < D[v][w]) 
					D[v][w] = D[v][u] + D[u][w];
}
int main()
{
	int m, x;
	int a,b;
	scanf("%d%d%d",&n,&m,&x);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i == j)
				road[i][j] = 0;
			else
				road[i][j] = INFINITY;
	for(int i = 0; i < m; i++) {
		scanf("%d%d",&a,&b);
		scanf("%d",&road[a][b]);
	}
	Floyd();
	int max = 0;
	for(int i = 1; i <= n; i++)
		if(D[i][x] < INFINITY  && D[x][i] < INFINITY && D[i][x] + D[x][i] > max)
			max = D[i][x] + D[x][i];
	printf("%d\n",max);
}