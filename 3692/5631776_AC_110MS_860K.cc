#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 210;
int map[N][N],match[N],g,b;
bool v[N],m[N][N];

bool dfs(int x)
{
	for(int i = 1; i <= b; i++)
		if(!v[i] && map[x][i]) {
			v[i] = true;
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
	for(int i= 1; i <= g; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

int main()
{
	int k(1),n,x,y;
	while(true)
	{
		memset(map,0,sizeof(map));
		memset(m,false,sizeof(m));
		scanf("%d%d%d",&g,&b,&n);
		if(!g && !b && !n)
			return 0;
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&x,&y);
			m[x][y] = true;
		}
		for(int i = 1; i <= g; i++) 
			for(int j = 1; j <= b; j++)
				if(!m[i][j])
					map[i][j] = 1;
		printf("Case %d: %d\n",k++,g+b-MaxMatch());
	}

	return 0;
}