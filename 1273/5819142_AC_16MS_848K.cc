#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N(210),INF(0x7fffffff);
//n为点的总个数
int f[N][N],q[N],cnt[3*N],e[N],d[N],n;
inline int maxflow(int source,int sink,int s,int t)
{
	int u,v,l(0),r(0),flow(0);
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	d[source] = n;
	for(u = s; u <= t; u++) {
		e[u] = f[source][u];
		f[u][source] = f[source][u];
		f[source][u] = 0;
		if(e[u]) {
			q[r++] = u;
			cnt[0]++;
		}
	}

	while(l != r)
	{
		u = q[l++];
		l %= n;
		for(v = s; v <= t; v++)
			if(f[u][v] > 0 && d[u]==(d[v]+1)) {
				int a = min(f[u][v],e[u]);
				f[u][v] -= a;
				f[v][u] += a;
				e[u] -= a;
				e[v] += a;
				if(e[v]==a && v!=source && v!=sink) {
					q[r++] = v;
					r %= n;
				}
			}
		if(e[u]>0 && u!=source && u!=sink)
		{
			int k = d[u];
			cnt[k]--;
			d[u] = 2*n+1;
			q[r++] = u;
			r %= n;
			for(v = s; v <= t; v++)
				if(f[u][v] && d[u]>(d[v]+1))
					d[u] = d[v]+1;
			cnt[d[u]]++;
			if(cnt[k] == 0) 
				for(v = s; v <= t; v++)
					if(d[v]>k && d[v]<n) {
						cnt[d[v]]--;
						d[v] = n;
						cnt[n]++;
					}
		}
	}
	for(v = s; v <= t; v++)
		flow += f[v][source];
	return flow;
}

int main()
{
	int x,y,l,m;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		memset(f,0,sizeof(f));
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&l);
			f[x][y] += l;
		}
		printf("%d\n",maxflow(1,n,1,n));
	}
	return 0;
}