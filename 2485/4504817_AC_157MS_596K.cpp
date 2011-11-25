#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
// 最大值
#define INF 99999999
// 最多的边数
#define N 500
// 路径储存
int road[N][N];
int main()
{
	int n,m,count;
	int i,j,k,l;
	int mink,min;
	scanf("%d",&m);
	while(m-- > 0) {
		scanf("%d",&n);
		for( i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d",&road[i][j]);
	//Prim最小生成树
		int res = 0;
		int lesscost[N];
		for(i = 0; i < n;i++) 
			lesscost[i] = road[0][i];
		for( i = 1; i < n ;i++) {
			min = INF;
			for(j = 0; j < n ; j++)
				if(lesscost[j] > 0 && lesscost[j] < min) {
					min = lesscost[j];
					mink = j;
				}
			if(res < min)
				res = min;
	// 将刚加入集合的节点的所有边和现有边做一个比较,保留小的边
			for(j = 0; j < n;j++)
				if(lesscost[j] > road[mink][j]) 
					lesscost[j] = road[mink][j];
		}
		printf("%d\n",res);
	}
}