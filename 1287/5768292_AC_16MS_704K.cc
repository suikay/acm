#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 100;
int net[N][N],d[N];
bool v[N];
int prim(int s,int t)
{
	memcpy(d,net[s],sizeof(net[s]));
	memset(v,false,sizeof(v));
	int now,nj,res;
	res = 0;
	v[s] = true;
	for(int i = s+1; i <= t; i++) {
		now = 0x7fffffff;
		for(int j = s+1; j <= t; j++)
			if(!v[j] && now > d[j]) {
				now = d[j];
				nj = j;
			}
		res += now;
		v[nj] = true;
		for(int j = s+1; j <= t; j++)
			if(!v[j] && d[j] > net[nj][j])
				d[j] = net[nj][j];
	}
	return res;
}

bool input(int &s,int &t)
{
	int n,x,y,q;
	s = 1;
	memset(net,0x7f,sizeof(net));
	if(scanf("%d%d",&t,&n)!=2)
		return false;
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d",&x,&y,&q);
		if(net[x][y] > q)
			net[x][y] = net[y][x] = q;
	}
	return true;
}

int main()
{
	int s,t;
	while(input(s,t))
		printf("%d\n",prim(s,t));

	return 0;
}