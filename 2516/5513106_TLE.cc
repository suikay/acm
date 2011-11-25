#include  <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MAX(110),INF(0x7fffffff);
int esp[MAX][MAX],cost[MAX],net[MAX][MAX],path[MAX];
int supply[MAX][MAX],need[MAX][MAX],supply_sum[MAX],need_sum[MAX];
bool Bellman_ford(int s,int t)
{
	bool flag;
	memset(path,-1,sizeof(path));
	for(int i = s; i <= t; i++)
		cost[i] = INF;
	cost[s] = 0;
	flag = true;
	path[s] = s;
	while(flag)
	{
		flag = false;
		for(int i = s; i <= t; i++) 
		{
			if(cost[i] == INF)
				continue;
			for(int j = s; j <= t; j++)
				if (net[i][j] > 0 && (cost[i] + esp[i][j]) < cost[j]) 
				{	
					flag = true;
					path[j] = i;
					cost[j] = cost[i] + esp[i][j];
				}
		}
	}
	return path[t] != -1;
}

int Edmonds_karp(int s,int t)
{
	int sum(0),now,neck;
	while(Bellman_ford(s,t))
	{
		now = t;
		while(now != path[now])
		{
			neck = min(neck,net[path[now]][now]);
			now = path[now];
		}
		now = t;
		while(now != path[now])
		{
			net[path[now]][now] -= neck;
			net[now][path[now]] += neck;
			esp[now][path[now]] = -esp[path[now]][now];
			now = path[now];
		}
		sum += neck * cost[t];
	}
	return sum;
}

bool input(int &n,int &m,int &k)
{
	memset(need_sum,0,sizeof(need_sum));
	memset(supply_sum,0,sizeof(supply_sum));
	scanf("%d%d%d",&n,&m,&k);
	if(!n && !m && !k)
		return false;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < k; j++) {
			scanf("%d",&need[i][j]);
			need_sum[j] += need[i][j];
	}
	for (int i = 1; i <= m; i++)
		for(int j = 0; j < k; j++) {
			scanf("%d",&supply[i][j]);
			supply_sum[j] += supply[i][j];
	}
	return true;
}

void input_2(int n,int m)
{
	for(int i = 1; i <= n; i++)
		for(int j = n+1; j <= m+n; j++)
			scanf("%d",&(esp[i][j]));
}
int main()
{
	int n,m,k,i,des,sum;
	bool valid;
	while(input(n,m,k))
	{
		valid = true;
		sum = 0;
		des = m + n + 1;
		for(i = 0; i < k; i++)
			if(supply_sum[i] < need_sum[i])
				valid = false;
		for(i = 0;i < k; i++) {
			input_2(n,m);
			if(!valid)
				continue;
			memset(net,0,sizeof(net));
			for(int j = 1; j <= n; j++)
				for(int k = n+1; k <= m+n; k++)
					net[j][k] = INF;
			for(int j = 1;j <= n; j++)
				net[0][j] = need[j][i];
			for(int j = n+1; j <= m+n; j++)
				net[j][des] = supply[j-n][i];
			sum += Edmonds_karp(0,des);
		}
		if(valid)
			printf("%d\n",sum);
		else
			printf("-1\n");
	}
	return 0;
}

