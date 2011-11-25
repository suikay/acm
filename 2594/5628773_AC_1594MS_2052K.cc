#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 600;
int map[N][N],match[N],m;
bool v[N];
bool dfs(int x)
{
	for(int i = 1; i <= m; i++)
		if(!v[i] && map[i][x])
		{
			v[i] = true;
			if(match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
	return false;
}
void floyd()
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++) {
		if(i == j)
			continue;
		for(int k = 1; k <= m; k++)
			if(map[j][i] && map[i][k])
				map[j][k] = 1;
	}
}
int maxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= m; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

int main()
{
	int n,x,y;
	while(true)
	{
		scanf("%d%d",&m,&n);
		if(!m && !n)
			return 0;
		memset(map,0,sizeof(map));
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&x,&y);
			map[x][y] = 1;
		}
		floyd();
		printf("%d\n",m-maxMatch());
	}

	return 0;
}