#include <stdio.h>
#define MAX 1001
#define INFINITY 999999999
int road[MAX][MAX];
int A[MAX];
int B[MAX];
int n;
/*
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
*/
void Dijkstra_a(int x)
{
	int final[MAX];
	int v;
	for(int i = 1; i <= n; i++) {
		final[i] = false;
		A[i] = road[i][x];
	}
	final[x] = true;
	int min = INFINITY;
	for(int i = 1; i < n; i++)	{
		min = INFINITY;
		for(int j = 1; j <= n; j++)
			if(!final[j] && A[j] < min)  {
				v = j;
				min = A[j] ;
			}
		final[v] = true;
		for(int j = 1; j <= n; j++)
			if(!final[j] && (A[v] + road[j][v] < A[j]))
				A[j] = A[v] + road[j][v];
	}


	for(int i = 1; i <= n; i++) {
		final[i] = false;
		B[i] = road[x][i];
	}
	final[x] = true;
	for(int i = 1; i < n; i++)	{
		min = INFINITY;
		for(int j = 1; j <= n; j++)
			if(!final[j] && B[j] < min)  {
				v = j;
				min = B[j] ;
			}
		final[v] = true;
		for(int j = 1; j <= n; j++)
			if(!final[j] && (B[v] + road[v][j] < B[j]))
				B[j] = B[v] + road[v][j];
	}
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
	Dijkstra_a(x);
	int max = 0;
	for(int i = 1; i <= n; i++)
		if(A[i] + B[i] > max)
			max =A[i] + B[i] ;
	printf("%d\n",max);
}