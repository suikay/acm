#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define min(a,b) ((a)>(b))?(b):(a)
using namespace std;
const int N = 60;
const int INF = 10000;
int n,m;
int f[N][N],q[N],d[N],e[N],cnt[3*N],orif[N][N];
int path[N*N];
bool v[N];
int findpath(int s,int t,int o,int e)
{
	int queue[N],l,r,k,d[N];
	memset(d,0,sizeof(d));
	memset(path,-1,sizeof(path));
	d[s] = INF;
	l = r = 0;
	queue[r++] = s;
	path[s] = -1;
	while(l!= r) {
		k = queue[l++];
		if(k == n)
			break;
		for(int i = o; i <= e; i++)
			if(d[k] > 0 && d[i] <= 0 && path[i] == -1 && f[k][i] > 0) {
				d[i] = min(d[k],f[k][i]);
				path[i] = k;
				queue[r++] = i;
			}
	}
	if(path[t] == -1)
		return -1;
	return d[t];
}
int FF(int s,int t,int o,int e)
{
	int step,res=0;
	while((step = findpath(s,t,o,e))!=-1) {
		res+= step;
		int l = t;
		while(l >= 0) {
			f[path[l]][l] -= step;
			f[l][path[l]] += step;
			l = path[l];
		}
	}
	return res;
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
		f[x][y]++;
		f[y][x]++;
	}
	return true;
}

int main()
{
	int tmp,res;
	while(input()) {
		res = 10000;
		for(int i= 0; i < n; i++) {
			if(i == 1)
				continue;
			memcpy(orif,f,sizeof(f));
			f[i][n] = INF;
			tmp = FF(1,i,0,n);
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
