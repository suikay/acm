#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
const int M(1100),N(110),INF(0x7fffffff);
bool v[M];
vector<int> pile[M];
int net[N][N],st[N],path[N],flow[N],pighouse[M];
int bfs(int s,int t)
{
	int top,end,now;
	top = end = 0;
	st[end++] = s;
	memset(path,-1,sizeof(path));
	path[s] = s;
	while(top < end)
	{
		now = st[top++];
		if(now == t)
			return flow[now];
		for(int i = 0; i <= t; i++)
			if(path[i] == -1 && net[now][i]) 
			{
				flow[i] = min(flow[now],net[now][i]);
				path[i] = now;
				st[end++] = i;
			}
	}
	return -1;
}

int Edmonds_karp(int s,int t)
{                                                                                                                                                                                                          
	int sum(0),now,tmp;
	while(true)
	{
		tmp = bfs(s,t);
		if(tmp == -1)
			break;
		sum += tmp;
		now = t;
		while(now != s)
		{
			net[path[now]][now] -= tmp;
			net[now][path[now]] += tmp;
			now = path[now];
		}
	}
	return sum;
}

bool init(int &m,int &n,int &des)
{
	int many,buy;

	if((scanf("%d%d",&m,&n)!=2))
		return false;
	memset(v,false,sizeof(v));
	memset(net,0,sizeof(net));
	flow[0] = INF;
	des = n + 1;

	for(int i = 1; i <= m; i++)
		scanf("%d",pighouse+i);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&many);
		for(int j = 0; j < many; j++) {
			scanf("%d",&buy);
			if(v[buy]) 
			{
				for(int k = 0; k < pile[buy].size();k++) 
					net[i][pile[buy][k]] = INF;
				pile[buy].push_back(i);
			}
			else 
			{
				v[buy] = true;
				pile[buy].push_back(i);
				net[i][des] += pighouse[buy];
			}
		}
		scanf("%d",net[0]+i);
	}
	return true;
}

int main()
{
	int m,n,des;
	while(init(m,n,des))
		printf("%d\n",Edmonds_karp(0,des));
	return 0;
}
