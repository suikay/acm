#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N(210),MaxFlow(0x7fffffff);
int st[N],path[N],flow[N],map[N][N];
int m,n;
inline int bfs(int &u,int &v,int &s,int &t)
{
	int top,end,now;
	memset(path,-1,sizeof(path));
	top = end = 0;
	st[end++] = u;
	path[u] = u;
	while(top < end) {
		now = st[top++];
		if(now == v)
			return flow[t];
		for(int i = s; i <= t; i++)
			if(i != s && path[i] == -1 && map[now][i])
			{
				path[i] = now;
				flow[i] = min(flow[now],map[now][i]);
				st[end++] = i;
			}
	}
	return -1;
}
inline int Edmonds_karp(int u,int v,int s,int t)
{
	int tmp,now,sum(0);
	while(true)
	{
		tmp = bfs(u,v,s,t);
		if(tmp == -1)
			break;
		sum += tmp;
		now = v;
		while(path[now] != now) {
			map[path[now]][now] -= tmp;
			map[now][path[now]] += tmp;
			now = path[now];
		}
	}
	return sum;
}
int main()
{
	int x,y,l;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		memset(map,0,sizeof(map));
		flow[1] = MaxFlow;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&l);
			map[x][y] += l;
		}
		printf("%d\n",Edmonds_karp(1,n,1,n));
	}
	return 0;
}