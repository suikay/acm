#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
 
using namespace std; 
#define typec int                   // type of res 
const int N = 20010;
int f[N][N],cnt[3*N],d[N],e[N],q[N];
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
						cnt[v]--;
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

int main()
{
	int m,n,u,v,w;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) 
		scanf("%d%d",&f[0][i],&f[i][n+1]);
	for(int i = 0; i < m; i++) {
		scanf("%d%d",&u,&v,&w);
		f[u][v] += w; f[v][u] += w;
	}
	printf("%d\n",maxflow(0,n+1));
	return 0;
}


