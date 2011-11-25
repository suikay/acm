#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 2000
typedef struct Edge{
	int u;
	int v;
	int w;
	bool operator() (Edge a,Edge b){
		return (a.w < b.w);
	}
}Edge;
Edge edge[N * (N + 1) / 2];
int parent[N];
int Find(int x)
{
	if( parent[x] >= 0) {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
	return x;
}
void Union(int x,int y)
{
	x = Find(x);
	y = Find(y);
	if( x == y)
		return ;
	if( parent[x] < parent[y])
		parent[y] = x;
	else {
		if(parent[x] == parent[y])
			parent[y]--;
		parent[x] = y;
	}
}
char type[2000][8];
int main()
{
	int n,eCount,count;
	int i,j,k;
	while(true) {
		scanf("%d",&n);
		if(!n)
			break;
		getchar();
		for(i = 0; i < n; i++)
			gets(type[i]);
		eCount = 0;
		memset(parent,-1,n*sizeof(int));
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n;j++) {
				count = 0;
				for(k = 0; k < 7; k++)
					if(type[i][k] != type[j][k])
						count++;
				edge[eCount].u = i;
				edge[eCount].v = j;
				edge[eCount].w = count;
				eCount++;
			}
		sort(edge,edge + eCount,Edge());
		count = 0;
		i = 0;
		int sum = 0;
		while(count < (n - 1)) {
			if(Find(edge[i].u) != Find(edge[i].v)) {
				Union(edge[i].u,edge[i].v);
				sum += edge[i].w;
				count ++;
			}
			i++;
		}
		printf("The highest possible quality is 1/%d.\n",sum);
	}
}