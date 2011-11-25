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
int f[N][N],q[N],cnt[3*N],e[N],d[N],n,m;
int maxflow(int s,int t)
{
	int u,v,l(0),r(0),flow(0);
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	d[s] = n;
	for(u = 1; u <= n; u++) {
		e[u] = f[s][u];
		f[u][s] = f[s][u];
		f[s][u] = 0;
		if(e[u]) {
			q[r++] = u;
			cnt[0]++;
		}
	}

	while(l != r)
	{
		u = q[l++];
		l %= n;
		for(v = 1; v <= n; v++)
			if(f[u][v] > 0 && d[u]==(d[v]+1)) {
				int a = min(f[u][v],e[u]);
				f[u][v] -= a;
				f[v][u] += a;
				e[u] -= a;
				e[v] += a;
				if(e[v]==a && v!=s && v!=t) {
					q[r++] = v;
					r %= n;
				}
			}
		if(e[u]>0 && u!=s && u!=t)
		{
			int k = d[u];
			cnt[k]--;
			d[u] = 2*n+1;
			q[r++] = u;
			r %= n;
			for(v = 1; v <= n; v++)
				if(f[u][v] && d[u]>(d[v]+1))
					d[u] = d[v]+1;
			cnt[d[u]]++;
			if(cnt[k] == 0) 
				for(v = 1; v <= n; v++)
					if(d[v]>k && d[v]<n) {
						cnt[d[v]]--;
						d[v] = n;
						cnt[n]++;
					}
		}
	}
	for(v = 1; v <= n; v++)
		flow += f[v][s];
	return flow;
}
int main()
{
	int x,y,l;
	while(scanf("%d%d",&m,&n) != EOF)
	{
		memset(f,0,sizeof(f));
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&l);
			f[x][y] += l;
		}
		printf("%d\n",maxflow(1,n));
	}
	return 0;
}
