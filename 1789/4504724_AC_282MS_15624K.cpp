#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
// 最大值
#define INF 99999999
// 最多的边数
#define N 2000
// 路径储存
int road[N][N];
char type[N][8];
// 保存节点是否被加入集合
int in[N],inv[N];
int main()
{
	int n,m,count;
	int i,j,k,l;
	int mink,min,res;
	while(true) {
		scanf("%d",&n);
		if(!n)
			break;
		getchar();
		for(i = 0; i < n; i++)
			gets(type[i]);
		memset(in,0,n*sizeof(int));
		memset(inv,0,n*sizeof(int));
		for(i = 0; i < n; i++) {
			road[i][i] = -1;
			for(j = i + 1; j < n;j++) {
				count = 0;
				for(k = 0; k < 7; k++)
					if(type[i][k] != type[j][k])
						count++;
				road[i][j] = road[j][i] = count;
			}
		}

		res = 0;
		int lesscost[N];
		for(i = 0; i < n;i++)
			lesscost[i] = road[0][i];
		for( i = 1; i < n ;i++) {
			min = INF;
			for(j = 0; j < n; j++)
				if(lesscost[j] >= 0 && lesscost[j] < min) {
					min = lesscost[j];
					mink = j;
				}
			res += min;
			for(j = 0; j < n;j++)
				if(lesscost[j] > road[mink][j])
					lesscost[j] = road[mink][j];
		}
		printf("The highest possible quality is 1/%d.\n",res);
		}
}