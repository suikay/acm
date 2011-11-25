#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define N 110
#define NIL 99999999
int f[N][N],cnt[3*N],d[N],e[N],q[N],x,y,t,s,z;
int n,np,nc,rc;
#define min(x,y) (x)>(y)?(y):(x);
int main()
{
	while(true)
	{
		memset(f,0,sizeof(f));
		if(scanf("%d%d%d%d",&n,&np,&nc,&rc)!= 4)
			return 0;
		for(int i = 0; i < rc; i++) {
			scanf(" (%d,%d)%d",&x,&y,&z);
			if(x == y)
				continue;
			f[x+1][y+1] = z;
		}
		for(int i = 0; i < np;i++) {
			scanf(" (%d)%d",&x,&y);
			f[0][x+1] = y;
		}
		for(int i = 0; i < nc; i++) {
			scanf(" (%d)%d",&x,&y);
			f[x+1][n+1] = y;
		}

		s = 0;t = n+1;
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
			while(e[u] > 0) 
			{
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
	//				q[r++] = u;
	//				r %= n;
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
		}
		for(v = s; v <= t; v++)
			flow += f[v][s];

		printf("%d\n",flow);
	}
	return 0;
}
