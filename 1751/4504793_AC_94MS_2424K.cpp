#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
// 最大值
#define INF 99999999
#define len(i,j) ((i)*(i) + (j)*(j))
// 最多的边数
#define N 751
// 路径储存
int road[N][N];
int main()
{
	int n,m,count;
	int i,j,k,l;
	int mink,min,res;
	scanf("%d",&n);
	int x[N],y[N];
	for(i = 1; i <= n; i++)
		scanf("%d%d",&x[i],&y[i]);
	for( i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				road[i][j] = -1;
			else
				road[i][j] = road[j][i] = len(x[i] - x[j],y[i] - y[j]);
	scanf("%d",&m);
	int u,v;
	for(i = 0; i < m;i++) {
		scanf("%d%d",&u,&v);
		road[v][u] = road[u][v] = 0;
	}
//Prim最小生成树
	res = 0;
	int lesscost[N];
	int ori[N];
	for(i = 1; i <= n;i++) {
		lesscost[i] = road[1][i];
		ori[i] = 1;
	}
	for( i = 1; i < n ;i++) {
		min = INF;
		for(j = 1; j <= n; j++)
			if(lesscost[j] >= 0 && lesscost[j] < min) {
				min = lesscost[j];
				mink = j;
			}
		if(min > 0)
			printf("%d %d\n",ori[mink],mink);
// 将刚加入集合的节点的所有边和现有边做一个比较,保留小的边
		for(j = 1; j <= n;j++)
			if(lesscost[j] > road[mink][j]) {
				lesscost[j] = road[mink][j];
				ori[j] = mink;
			}
	}
}