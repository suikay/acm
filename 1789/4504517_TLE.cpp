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
		cin >> n;
		if(!n)
			break;
		for(i = 0; i < n; i++)
			cin >> type[i];
		memset(in,0,N*sizeof(int));
		memset(inv,0,N*sizeof(int));
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n;j++) {
				count = 0;
				for(k = 0; k < 7; k++)
					if(type[i][k] != type[j][k])
						count++;
				road[i][j] = road[j][i] = count;
			}
		in[0] = 0;
		inv[0] = 1;
		res = 0;
		for( j = 1; j < n ;j++) {
			min = INF;
			for(k = 0; k < j ;k++)
				for( l = 0; l < n; l++)
					if( !inv[l] && road[in[k]][l] && road[in[k]][l] < min) {
						mink = l;
						min = road[in[k]][l];
					}
			inv[mink] = 1;
			in[j] = mink;
			// 因为求的是最小生成树最大边,在这判断
			res += min;
		}
		printf("The highest possible quality is 1/%d.\n",res);
	}
}