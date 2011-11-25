#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
struct Edge
{
	int a,b,c,p,r;
	bool ch[1100];
	bool operator()(const Edge &x,const Edge &y) {
		return x.a < y.a;
	}
};
Edge edge[10];
bool v[15];
int money[15],n,m,res;
void dfs(int place,int status)
{
	int cost,last_m,last_v;
	if(place == n) {
		if(money[n] < res) {
			res = money[n];
		}
		return ;
	}
	for(int i = 0; i < m; i++) 
		if(!edge[i].ch[status] && edge[i].a == place) {
			last_m = money[edge[i].b];
			last_v = v[edge[i].b];
			if(v[edge[i].c] && (edge[i].p < edge[i].r)) 
				cost = edge[i].p;
			else
				cost = edge[i].r;
			money[edge[i].b] = money[edge[i].a] + cost;
			v[edge[i].b] = true;
			edge[i].ch[status] = true;
			dfs(edge[i].b,status|(1 << (edge[i].b - 1)));
			edge[i].ch[status] = false;
			money[edge[i].b] = last_m;
			v[edge[i].b] = last_v;
		}
}

	
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> edge[i].a >> edge[i].b >> edge[i].c >>
			edge[i].p >> edge[i].r;
	sort(edge,edge+m,Edge());
	res = 0x7fffffff;
	memset(v,false,sizeof(v));
	v[1] = true;
	money[1] = 0;
	dfs(1,1);
	if(res != 0x7fffffff)
		cout << res << endl;
	else
		cout << "impossible" << endl;
	return 0;
}

/*
4 5
1 2 1 10 10
2 3 1 30 50
3 4 3 80 80
2 1 2 10 10
1 3 2 10 50
*/