#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool v[500],check[500];
int _map[500][500],m,n,match[500];
bool fe(int x)
{
	for(int i = n+1; i <= m+n; i++)
	{
		if(!check[i] && _map[x][i]) {
			check[i] = true;
			if(match[i] == -1 || fe(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= n; i++) {
		memset(check,false,sizeof(check));
		if(fe(i)) {
			v[i] = true;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	int k,tmp,x;
	scanf("%d",&k);
	while(k--)
	{
		memset(v,false,sizeof(v));
		memset(_map,0,sizeof(_map));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++) {
			scanf("%d",&tmp);
			for(int j = 0; j < tmp; j++) {
				scanf("%d",&x);
				_map[i][x+n] = 1;
			}
		}
		if(MaxMatch() == n)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}