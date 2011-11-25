#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 210;
int map[N][N],m,n,a[N],b[N],match[N],k;
bool check[N];

bool dfs(int x)
{
	for(int i = 0; i < m; i++)
		if(!check[i] && map[x][i]) {
			check[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
			}
		}
	return false;
}


int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i < n; i++) {
		memset(check,false,sizeof(check));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

int main()
{
	int num,zero,x,y;
	while(scanf("%d",&n))
	{
		if(!n)
			return 0;
		memset(map,0,sizeof(map));
		scanf("%d%d",&m,&k);
		for(int i = 0; i < k; i++) {
			scanf("%d%d%d",&num,&x,&y);
			if(x*y != 0)
				map[x][y] = 1;
		}
		printf("%d\n",MaxMatch());
	}

	return 0;
}