#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <math.h>
#define dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;
const int N = 410;
const int INF = 100000;
int ice,p[N],c[N],f[2*N][2*N],orif[2*N][2*N],sum;
double dd,x[N],y[N];
int d[2*N],e[2*N],q[2*N],cnt[6*N];

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
			if(f[u][v] > 0 && (d[u] == (d[v] + 1)) && e[u] > 0) {
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
		flow += f[t][v];
	return flow;
}

void input()
{
	memset(f,0,sizeof(f));
	sum = 0;
	scanf("%d%lf",&ice,&dd);
	for(int i = 1; i <= ice; i++) {
		scanf("%lf%lf%d%d",x+i,y+i,p+i,c+i);
		sum += p[i];
	}
	for(int i = 1; i <= ice; i++)
		for(int j = 1; j <= ice; j++)
			if(i != j )
				if(dis(x[i],y[i],x[j],y[j]) <= dd) {
					f[ice+i][j] = INF;
					f[j+ice][i] = INF;
				}
	for(int i = 1; i <= ice; i++) {
		f[0][i] = p[i];
		f[i][i+ice] = c[i];
	}
}

int main()
{
	int des,now,k;
	vector<int> res;
	scanf("%d",&k);
	while(k--) {
		input();
		res.resize(0);
		des = 2*ice+1;
		memcpy(orif,f,sizeof(f));
		for(int i = 1; i <= ice; i++) {
			memcpy(f,orif,sizeof(f));
			f[i][des] = INF;
			now = maxflow(0,des);
			if(now == sum) 
				res.push_back(i-1);
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