#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 500;
int map[N][N],match[N],n;
bool v[N];
bool dfs(int x)
{
	for(int i = 1; i <= n; i++)
		if(!v[i] && map[x][i])
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

int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= n; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}
		
int main()
{
	int k,x,y;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < k; i++) {
		scanf("%d%d",&x,&y);
		map[x][y] = 1;
	}
	printf("%d\n",MaxMatch());

	return 0;
}