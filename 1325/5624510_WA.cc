#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 2100;
int map[N][N],m,n,a[N],b[N],match[N],k;
bool check[N];

bool dfs(int x)
{
	for(int i = k; i < 2*k; i++)
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
	for(int i = 0; i < k; i++) {
		memset(check,false,sizeof(check));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}
int main()
{
	int num;
	while(scanf("%d%d%d",&n,&m,&k) == 3)
	{
		for(int i = 0; i < k; i++) {
			scanf("%d",&num);
			scanf("%d%d",a+num,b+num);
		}
		for(int i = 0; i < k; i++)
			for(int j = i+1; j < k; j++)
				if(a[i] == a[j])
					map[i][j+k] = 1;
				else if( b[i] == b[j])
					map[j][i+k] = 1;
		printf("%d\n",k-MaxMatch());
	}

	return 0;
}