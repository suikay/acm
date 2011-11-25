#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
const int N = 110;
const int INF = 0x3fffffff;
int n,p[N],c[N],f[2*N][2*N],orif[2*N][2*N],sum;
double dd,x[N],y[N];
int d[2*N],e[2*N],q[2*N],cnt[6*N];

double dis(double &x,double &y,double &xx,double &yy) {
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

int maxflow(int s,int t)
{
	int u,v,l(0),r(0),flow(0),n(t+1);
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	memset(cnt,0,sizeof(cnt));
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

bool input()
{
	memset(f,0,sizeof(f));
	sum = 0;
	scanf("%d%lf",&n,&dd);
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf%d%d",x+i,y+i,p+i,c+i);
		sum += p[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j )
				if(dis(x[i],y[i],x[j],y[j]) <= dd) {
					f[n+i][j] = INF;
					f[j+n][i] = INF;
				}
	for(int i = 1; i <= n; i++) {
		f[0][i] = p[i];
		f[i][i+n] = c[i];
	}
	return true;
}

int main()
{
	int des,now,k;
	bool check;
	vector<int> res;
	scanf("%d",&k);
	while(k--) {
		input();
		res.resize(0);
		des = 2*n+1;
		check = false;
		for(int i = 1; i <= n; i++) {
			memcpy(orif,f,sizeof(f));
			f[i][des] = INF;
			now = maxflow(0,des);
			if(now == sum) {
				check = true;
				res.push_back(i-1);
			}
			memcpy(f,orif,sizeof(f));
		}
		if(res.size()==0)
			printf("-1\n");
		else {
			for(int i = 0; i < res.size()-1; i++)
				printf("%d ",res[i]);
			printf("%d\n",res[res.size()-1]);
		}
	}

	return 0;
}