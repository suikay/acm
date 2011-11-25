#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N(910),INF(0x0fffffff);
int m;
int f[N][N],q[1000000],cnt[3*N],e[N],d[N];
//点的序号为s..t,求source到sink的最大流
inline int maxflow(int source,int sink,int s,int t)
{
    int u,v,l(0),r(0),flow(0),n;
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
	n = t-s+1;
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
        //cout << " U " << u << endl;
        //l %= n;
        for(v = s; v <= t; v++)
            if(f[u][v] > 0 && d[u]==(d[v]+1)) {
                int a = min(f[u][v],e[u]);
                f[u][v] -= a;
                f[v][u] += a;
                e[u] -= a;
                e[v] += a;
                if(e[v]==a && v!=source && v!=sink) {
                    q[r++] = v;
                    //r %= n;
                }
            }
        if(e[u]>0 && u!=source && u!=sink)
        {
            int k = d[u];
            cnt[k]--;
            d[u] = 2*n+1;
            q[r++] = u;
        //    r %= n;
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
int ori[N][N];
int main()
{
	int n,s,t,last,now;
	scanf("%d%d%d",&n,&s,&t);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			scanf("%d",&(f[i][j]));
			if(f[i][j] && i != j)
				f[i+n][j] = 1;
			f[i][j] = 0;
		}
	for(int i = 1; i <= n; i++) {
		f[i][i+n] = 1;
		f[i+n][s] = 0;
		f[t+n][i] = 0;
	}
	if(f[n+t][s] || f[s+n][t])
	{
		puts("NO ANSWER!");
		return 0;
	}
	f[t][n+t] = 0;
	memcpy(ori,f,sizeof(f));
	printf("%d\n",last=maxflow(s+n,t,1,2*n));
	for(int i = 1; i <= n; i++)
	{
		if(i == s || i == t)
			continue;
		ori[i][i+n] = 0;
		memcpy(f,ori,sizeof(f));
		now = maxflow(s+n,t,1,2*n);
		if(now != last) {
			last = now;
			printf("%d ",i);
		}
	}
	puts("");

	return 0;
}
/*
4 1 3
1 1 0 1
1 1 1 1
0 1 1 1
1 1 1 1
9 1 9
1 1 1 1 0 0 0 0 0
1 1 0 0 0 1 0 0 0
1 0 1 0 1 0 0 0 0
1 0 0 1 0 0 1 0 0
0 0 1 0 1 0 0 1 0
0 1 0 0 0 1 0 1 0
0 0 0 1 0 0 1 0 1
0 0 0 0 1 1 0 1 1
0 0 0 0 0 0 1 1 1
*/