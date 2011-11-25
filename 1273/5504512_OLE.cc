#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N(210),MaxFlow(20000000);
int st[N],path[N],flow[N],map[N][N];
int m,n;
int bfs(int s,int t)
{
	int top,end,now;
	top = end = 0;
	st[end++] = s;
	memset(path,-1,sizeof(path));
	path[s] = s;
	while(top < end) {
		now = st[top++];
		if(now == t)
			return flow[t];
		for(int i = 1; i <= n; i++)
			if(i != s && path[i] == -1 && map[now][i])
			{
				path[i] = now;
				flow[i] = min(flow[now],map[now][i]);
				st[end++] = i;
			}
	}
	return -1;
}
int Edmonds_karp(int s,int t)
{
	int tmp,now,sum(0);
	while(true)
	{
		tmp = bfs(s,t);
		if(tmp == -1)
			break;
		sum += tmp;
		now = t;
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
	while(scanf("%d%d",&m,&n))
	{
		memset(map,0,sizeof(map));
		flow[1] = MaxFlow;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&l);
			map[x][y] = l;
		}
		printf("%d\n",Edmonds_karp(1,n));
	}
	return 0;
}

