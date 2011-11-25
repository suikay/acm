#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 60;
const int INF = 10000;
int n,m;
int f[N][N],q[N],d[N],e[N],cnt[3*N],orif[N][N];
int path[N*N];
int findpath()
{
	int queue[N],h,t;
	int k;
	int d[N];
	memset(d,0,sizeof(d));
	memset(path,-1,sizeof(path));;
	d[0] = INF;
	h = t = 0;
	queue[t++] = 0;
	path[0] = 0;
	while(h!= t) {
		k = queue[h++];
		if(k == n)
			break;
		for(int i = 1; i <= n+1; i++)
			if(d[k] > 0 && path[i] == -1 && f[k][i] > 0) {
				d[i] = min(d[k],f[k][i]);
				path[i] = k;
				queue[t++] = i;
			}
	}
	if(path[n] == -1)
		return -1;
	return d[n];
}
int FF()
{
	int step,res=0;
	while((step = findpath())!=-1) {
		res+= step;
		int l = n;
		while(l) {
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
		for(int i= 1; i < n; i++) {
			memcpy(orif,f,sizeof(f));
			f[i][n] = INF;
			tmp = FF();
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
