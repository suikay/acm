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
		//	cout << now <<" " ;
			net[path[now]][now] -= tmp;
			net[now][path[now]] += tmp;
			now = path[now];
		}
		//cout << tmp << endl;
	}
//	for(int i = s; i <= t; i++) {
//		for(int j = s; j <= t; j++)
//			cout << net[i][j] << " ";
//		cout << endl;
//	}
	return sum;
}

bool init(int &m,int &n,int &des)
{
	int many,buy;

	if(!(cin >> m >> n))
		return false;
	memset(v,false,sizeof(v));
	memset(net,0,sizeof(net));
	flow[0] = INF;
	des = n + 1;

	for(int i = 1; i <= m; i++)
		cin >> pighouse[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> many;
		for(int j = 0; j < many; j++) {
			cin >> buy;
//			cout << i << " " << j << ":" << buy << endl;
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
//			cout << "to des" << net[i][des] << endl;
		cin >> net[0][i];
	}
	return true;
}

int main()
{
	int m,n,des;
	while(init(m,n,des))
		cout << Edmonds_karp(0,des) << endl;
	return 0;
}
