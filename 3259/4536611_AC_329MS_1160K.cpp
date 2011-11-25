#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAXNODE 501
#define NIL 99999999
int road[MAXNODE][MAXNODE];
bool BF(int n,int s)
{
	bool in[MAXNODE];
	int stack[MAXNODE],count[MAXNODE],d[MAXNODE];
	memset(count,0,MAXNODE*sizeof(int));
	memset(stack,0,MAXNODE*sizeof(int));
	memset(in,false,MAXNODE*sizeof(bool));
	in[s] = true;
	for(int i = 1; i <= n; i++)
		d[i] = NIL;
	d[s] = 0;
	int top = 0,u;
	stack[top++] = s;
	while(top) {
		u = stack[--top];
		if(count[u]++ > n)
			return false;
		in[u] = false;
		for(int i = 1; i <= n; i++)
			if(d[u] + road[u][i] < d[i]) {
				if(!in[i]) {
					in[i] = true;
					stack[top++] = i;
				}
			d[i] = d[u] + road[u][i];
			}
	}
}
int main()
{
	int n,m,w,time;
	int x,y,xy;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&n,&m,&w);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i == j )
					road[i][j] = 0;
				else
					road[i][j] = NIL;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&xy);
			if(road[x][y] == NIL || road[x][y] > xy)
				road[x][y] = road[y][x] = xy;
		}
		for(int i = 0; i < w; i++) {
			scanf("%d%d%d",&x,&y,&xy);
			if(road[x][y]==NIL || road[x][y] > -xy)
				road[x][y] = -xy;
		}
		if(!BF(n,0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}