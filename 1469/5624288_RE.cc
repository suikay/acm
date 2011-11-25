#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool v[330],check[330];
int _map[310][310],m,n;
bool fe(int x)
{
	for(int i = 1; i <= m+n; i++)
	{
		if(!check[i] && _map[x][i]) {
			check[i] = true;
			if(!v[i]) {
				v[i] = true;
				_map[i][x] = 1;
				_map[x][i] = 0;
				return true;
			}
			else if(fe(i)) {
				_map[i][x] = 1;
				_map[x][i] = 0;
				return true;
			}
		}
	}
	return false;
}
int MM()
{
	int cnt(0);
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
		if(MM() == n)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}