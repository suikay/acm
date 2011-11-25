#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N(210),INF(0x0fffffff);
int m,n;
int f[N][N],q[1000000],cnt[3*N],e[N],d[N];
//点的序号为s..t,求source到sink的最大流
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
bool input()
{
	char tmp;
	int x,y;
	memset(f,0,sizeof(f));
	if(scanf("%d%d",&n,&m) != 2)
		return false;
	for(int i = 0; i < m; i++) {
		cin >> tmp >> x >> tmp >> y >> tmp;
		f[x][y] = f[y][x] = 1;
	}
	for(int i = 0; i < n; i++)
		f[i][0] = 0;
	return true;
}
int main()
{
	int tmp,res,orif[N][N];
	while(input()) {
		res = 10000;
		for(int i= 1; i < n; i++) {
			memcpy(orif,f,sizeof(f));
			memset(f[i],0,sizeof(f[i]));
			//f[i][n] = INF;
			tmp = maxflow(0,i,0,n-1);
			if(tmp < res)
				res = tmp;
			memcpy(f,orif,sizeof(orif));
		}
		if(res == 10000)
			res = 0;
		if(res == n-1)
			cout << n << endl;
		else
			cout << res << endl;
	}

	return 0;
}