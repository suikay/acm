#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct Road {
	int u;
	int v;
	unsigned long long w;
bool operator() (Road a,Road b){
	return (a.w > b.w);
}
}Road;
Road road[10000];
int parent[2001];
int FindParent(int x)
{
	if(parent[x] > 0) {
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
	else
		return x;
}
void Union(int x,int y)
{
	x = FindParent(x);
	y = FindParent(y);
	if( x == y)
		return ;
	if(parent[x] < parent[y]) 
		parent[y] = x;
	else
		if(parent[x] > parent[y])
			parent[x] = y;
		else {
			parent[x]--;
			parent[y] = x;
		}
}
int main()
{
	int n,m;
	unsigned long long max;
	int count = 0;
	scanf("%d%d",&n,&m);
	for( int i = 0; i < m; i++) 
		scanf("%d%d%llu",&road[i].u,&road[i].v,&road[i].w);
	sort(road,road+m,Road());
	for( int i = 0; i < n; i++)
		if(FindParent(road[count].u) != FindParent(road[count].v)) {
			Union(road[count].u,road[count].v);
			max = road[count].w;
			count ++;
		}
	printf("%llu\n",max);
}