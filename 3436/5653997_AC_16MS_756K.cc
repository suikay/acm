#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 60;
const int INF = 100000;
int orif[N][N],f[N][N],d[N],e[N],cnt[N],q[N];

int maxflow(int s,int t)
{
	int u,v,l(0),r(0),flow(0),n(t-s+1);
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	memset(cnt,0,sizeof(cnt));
	d[s] = n;
	for(u = s; u <= t; u++) {
		e[u] = f[s][u];
		f[u][s] = e[u];
		f[s][u] = 0;
		if(e[u] > 0 && u != t) {
			q[r++] = u;
			cnt[0]++;
		}
	}
	while(l != r)
	{
		u = q[l++];
		l %= n;
		for(v = s; v <= t; v++)
			if(f[u][v] > 0 && (d[u]==(d[v]+1)) && e[u]) {
				 int a = min(e[u],f[u][v]);
				 f[u][v] -= a;
				 f[v][u] += a;
				 e[u] -= a;
				 e[v] += a;
				 if(e[v] == a && v != s && v != t) {
					 q[r++] = v;
					 r %= n;
				 }
			}
		if(e[u] > 0 && u != s && u != t)
		{
			int k = d[u];
			q[r++] = u;
			r %= n;
			cnt[k]--;
			d[u] = 2*n + 1;
			for(v = s; v <= t; v++)
				if(f[u][v] && (d[u] > (d[v]+1))) 
					d[u] = d[v] + 1;
			cnt[d[u]]++;
			if(d[k] == 0) 
				for(v = s; v <= t; v++)
					if(d[v] > k && d[v] < n) {
						cnt[d[v]]--;
						d[v] = n;
						cnt[n]++;
					}
		}
	}
	for(u = s; u <= t; u++)
		flow += f[u][s];
	return flow;
}
int p[55][15],pp[55][15],h[55],a,b;
bool check(int x,int y)
{
	for(int i = 0; i < a; i++)
		if(p[y][i] == 2)
			continue;
		else
			if(p[y][i] != pp[x][i])
				return false;
	return true;
}

bool input(int &des)
{
	if((scanf("%d%d",&a,&b))!= 2)
		return false;
	des = b+1;
	memset(pp[0],0,sizeof(pp[0]));
	memset(f,0,sizeof(f));
	for(int i = 0; i < a; i++)
		p[des][i] = 1;
	for(int i = 1; i <= b; i++) {
		scanf("%d",h+i);
		for(int j = 0; j < a; j++)
			scanf("%d",p[i]+j);
		for(int j = 0; j < a; j++)
			scanf("%d",pp[i]+j);
	}
	for(int i = 1; i <= b; i++) {
		if(check(0,i))
			f[0][i] = h[i];
		if(check(i,des))
			f[i][des] = h[i];
	}
	for(int i = 1; i <= b; i++)
		for(int j = 1; j <= b; j++)
			if(i != j && check(i,j))
				f[i][j] = min(h[i],h[j]);
	memcpy(orif,f,sizeof(f));
	return true;
}

char tmp[100000];
int main()
{
	int des,cnt;
	while(input(des)) {
		printf("%d ",maxflow(0,des));
		cnt = 0;
		stringstream ss;
		for(int i = 1; i < des; i++)
			for(int j = 1; j < des; j++)
				if(orif[i][j] > f[i][j]) {
					cnt++;
					ss << i << " " << j << " " << orif[i][j]-f[i][j] << endl;
				}
		printf("%d\n",cnt);
		cout << ss.str();
	}

	return 0;
}