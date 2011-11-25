#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX(110),INF(0x7f7f7f7f);
int cost[2*MAX],path[2*MAX],d[2*MAX][2*MAX];
bool net[MAX*2][MAX*2];
struct Point
{
	int x,y;
	Point(int a,int b) {
		x = a;
		y = b;
	}
};
vector<Point> home,man;
int dis(const Point &a,const Point &b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}
bool bellman_ford(int s,int t)
{
	bool flag;
	memset(cost,0x7f,sizeof(cost));
	memset(path,-1,sizeof(path));
	cost[s] = 0;
	flag = true;
	while(flag)
	{
		flag = false;
		for(int i = s; i <= t; i++) 
		{
			if(cost[i] == INF)
				continue;
			for(int j = s; j <= t; j++)
				if(net[i][j] && (cost[i] + d[i][j] < cost[j]))
				{
					flag = true;
					cost[j] = cost[i] + d[i][j];
					path[j] = i;
				}
		}
	}
	return cost[t] != INF;
}

int Edmonds_karp(int s,int t)
{
	int sum(0),now;
	while (bellman_ford(s,t))
	{
		now = t;
		while (now != s)
		{
			net[path[now]][now] = false;
			net[now][path[now]] = true;
			d[now][path[now]] = -d[now][path[now]];
			now = path[now];
		}
		sum += cost[t];
	}
	return sum;
}

bool input(int &m,int &n,int &des)
{
	string tmp;
	memset(net,false,sizeof(net));
	memset(d,0,sizeof(d));
	home.clear();
	man.clear();
	cin >> m >> n;
	if(!m && !n)
		return false;
	for(int i = 0; i < m; i++) 
	{
		cin >> tmp;
		for(int j = 0; j < n; j++) 
			if (tmp[j] == 'H') 
				home.push_back(Point(i,j));
			else if (tmp[j] == 'm')
				man.push_back(Point(i,j));
	}
	int home_count(home.size()),man_count(man.size());
	des = home_count+man_count+1;
	//cout << "HC:" << home_count << "MC:" << man_count << endl;
	for(int i = 0; i < home_count; i++) {
		for(int j = 0; j < man_count; j++) {
			net[i+1][home_count+j+1] = true;
			d[i+1][home_count+j+1] = dis(home[i],man[j]);
		//	cout << d[i+1][home_count+j+1]<<" " ;
//			d[home_count+j+1][i+1] = -d[i+1][home_count+j+1];
		}
	//	cout << endl;
	}
	for(int i = 1; i <= home_count; i++)
		net[0][i] = true;
	for(int i = 1; i <= man_count; i++)
		net[i+home_count][des] = true;
	return true;
}

int main()
{
	int m,n,des;
	while(input(m,n,des))
		cout << Edmonds_karp(0,des) << endl;
	return 0;
}