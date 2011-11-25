#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 13;
int x[N],y[N],n;
bool v[N];
int dfs(int lx,int ly,int use)
{
	if(use == n) 
		return abs(x[n]-lx)+abs(y[n]-ly);
	int res = 0x7fffff;
	for(int i = 0; i < n; i++)
		if(!v[i]) {
			v[i] = true;
			int tmp = abs(lx-x[i])+abs(ly-y[i]) + dfs(x[i],y[i],use+1);
			if(tmp < res)
				res = tmp;
			v[i] = false;
		}
	return res;
}
int main()
{
	int k,ox,oy,d;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d%d%d",&d,&d,&ox,&oy);
		scanf("%d",&n);
		memset(v,false,sizeof(v));
		for(int i = 0; i < n; i++)
			scanf("%d%d",x+i,y+i);
		x[n] = ox; y[n] = oy;
		printf("The shortest path has length %d\n",dfs(ox,oy,0));
	}

	return 0;
}