#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
const int M(1100),N(110),INF(0x7fffffff);
bool v[M];
vector<int> pile[M];
int f[N][N],pighouse[M];
int e[N],d[N],cnt[3*N],q[N];

int maxflow(int s,int t)
{
	int u,v,l(0),r(0),flow(0),n(t+1);
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	d[s] = n;
	for(u = s; u <= t; u++) {
		e[u] = f[s][u];
		f[u][s] = f[s][u];
		f[s][u] = 0;
		if(e[u] > 0 && u != t) {
			q[r++] = u;
			cnt[d[u]]++;
		}
	}

	while(l != r)
	{
		u = q[l++];
		l %= n;
		for(v = s; v <= t; v++)
			if(f[u][v] > 0 && (d[u] == (d[v] + 1)) && e[u]) {
				int a = min(f[u][v],e[u]);
				f[u][v] -= a;
				f[v][u] += a;
				e[u] -= a;
				e[v] += a;
				if(e[v] == a && v != s && v != t) {
					q[r++] = v;
					r %= n;
				}
			}
			if(e[u] > 0 && u != s && u != t) {
				q[r++] = u;
				r %= n;
				int k = d[u];
				d[u] = 2*n + 1;
				for(v = s; v <= t; v++) 
					if(f[u][v] && (d[u] > (d[v]+1)))
						d[u] = d[v] + 1;
				cnt[k]--;
				cnt[d[u]]++;
				if(cnt[k] == 0) {
					for(v = s; v <= t; v++)
						if(d[v] > k && d[v] < n) {
							cnt[d[v]]--;
							d[v] = n;
							cnt[n]++;
						}
				}
			}
	}
	for(v = s; v <= t; v++)
		flow += f[v][s];
	return flow;
}

bool init(int &m,int &n,int &des)
{
	int many,buy;

	if(!(cin >> m >> n))
		return false;
	memset(v,false,sizeof(v));
	memset(f,0,sizeof(f));
	des = n + 1;

	for(int i = 1; i <= m; i++)
		cin >> pighouse[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> many;
		for(int j = 0; j < many; j++) {
			cin >> buy;
			if(v[buy]) 
			{
				for(int k = 0; k < pile[buy].size();k++) 
					f[i][pile[buy][k]] = INF;
				pile[buy].push_back(i);
			}
			else 
			{
				v[buy] = true;
				pile[buy].push_back(i);
				f[i][des] += pighouse[buy];
			}
		}
		cin >> f[0][i];
	}
	return true;
}

int main()
{
	int m,n,des;
	while(init(m,n,des))
		cout << maxflow(0,des) << endl;
	return 0;
}
