#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
map<string,int> type;
const int N(1000),INF(0x7fffffff);
int path[N],net[N][N],flow[N],st[N];
vector<int> device;

int bfs(int s,int t)
{
	int top,end,now;
	top = end = 0;
	st[end++] = s;
	memset(path,-1,sizeof(path));
	path[s] = s;
	flow[s] = INF;
	while(top < end)
	{
		now = st[top++];
		if(now == t)
			return flow[now];
		for(int i = 1; i <= t; i++)
			if(path[i] == -1 && net[now][i])
			{
				flow[i] = min(flow[now],net[now][i]);
				path[i] = now;
				st[end++] = i;
			}
//			cout << "In the bfs" << endl;
	}
	return -1;
}


int Edmonds_Karp(int s,int t)
{
	int sum(0),now,tmp;
	while(true)
	{
		tmp = bfs(s,t);
		if(tmp == -1)
			break;
		sum += tmp;
		now = t;
		while(path[now] != now)
		{
			net[path[now]][now] -= tmp;
			net[now][path[now]] += tmp;
			now = path[now];
		}
//		cout << "Edmonds_Karp" << endl;
	}
	return sum;
}


void input(int &n,int &m,int &k,int &des)
{
	memset(net,0,sizeof(net));
//	memset(beplug,false,sizeof(beplug));
	int type_no(1);
	string name1,name2;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> name1;
		if(type.count(name1) == 0)
			type[name1] = type_no++;
		net[0][type[name1]]++;
//		beplug[type[name1]] = true;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> name1 >> name2;
		if(type.count(name1) == 0)
			type[name1] = type_no++;
		if(type.count(name2) == 0)
			type[name2] = type_no++;
		net[type[name2]][type[name1]]++;
		device.push_back(type[name1]);
//		beplug[type[name2]] = true;
	}
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> name1 >> name2;
		if(type.count(name1) == 0)
			type[name1] = type_no++;
		if(type.count(name2) == 0)
			type[name2] = type_no++;
		net[type[name2]][type[name1]] = INF;
	}
	des = type_no;
	for(int i = 0; i < device.size(); i++)
		net[device[i]][des]++;
}

int main()
{
	int n,m,k,des;
	input(n,m,k,des);
//	cout << "After input" << endl;
	cout << Edmonds_Karp(0,des) << endl;
	return 0;
}
