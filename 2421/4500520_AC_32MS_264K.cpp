#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Edge
{
	int x;
	int y;
	int lenght;
}Edge;
Edge edge[4950];
int parent[101];
int compare(const void* a,const void* b)
{
	return ((Edge*)a)->lenght - ((Edge*)b)->lenght;
}
//寻父节点加压缩路径
int FindParent(int x)
{
	if(parent[x] > 0 ){
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
	return x;
}
//合并集合 用祖先节点的parent(<0)的绝对值来表示后代的个数
//将后代少的加入后代多的 这样能减少寻找父节点的运算量
void MergeSet(int x,int y)
{
	x = FindParent(x);
	y = FindParent(y);
	// notice:在加入x,y时有可能x,y已经在同一集合里边了
	// 我就栽在这的
	if( x == y)
		return ;
	if( parent[x] < parent[y])  {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
			parent[y] += parent[x];
			parent[x] = y;
		}		
}
int main()
{
	int n,count ,lenght;
	unsigned long long sum;
	int x,y,m;
	int null;
	char s[100];
	scanf("%d",&n);
	count = 0;
	for( int i = 1; i <= n; i++) {
		for(int j = 1; j < i;j++) {
			scanf("%d",&lenght);
			edge[count].x = i;
			edge[count].y = j;
			edge[count].lenght = lenght;
			count++;
		}
		//因为用的是Kruskal,只需读取上三角的数据
		//现将多余的数据用null吞掉
		for(int j = i; j <= n;j++)
			scanf("%d",&null);
	}
	for( int i = 1; i <= n; i++)
		parent[i] = 0;
	qsort(edge,count,sizeof(Edge),compare);
	//在这读入已经存在的路
	scanf("%d",&m);
	for( int i = 0; i < m; i++) {
		scanf("%d%d",&x,&y);
		MergeSet(x,y);
	}
	sum = 0;
	//notice:不可以用 cout > 0 作为循环条件
	//因为有可能在  加入存在的路时有多余的路径
	//例如a,b已经间接连通,但后边又给了一个a,b直接连通的路
	for( int i = 0;i < count; i++) 
		if(FindParent(edge[i].x) != FindParent(edge[i].y)) {
			MergeSet(edge[i].x,edge[i].y);
			sum += edge[i].lenght;
		}
		printf("%d\n",sum);
}