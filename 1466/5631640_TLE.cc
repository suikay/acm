#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 510;
int map[N][N],match[N],n;
bool v[N];

bool dfs(int x)
{
	for(int i = 0; i < n; i++)
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
	for(int i = 0; i < n; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

int main()
{
	char dummy[100];
	int m,tmp,k;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i++) {
			scanf("%d",&m);
			getchar();getchar();getchar();
			scanf("%d",&k); getchar();
			for(int j = 0; j < k; j++) {
				scanf("%d",&tmp);
				map[min(m,tmp)][max(m,tmp)] = 1;
			}
			gets(dummy);
		}
		printf("%d\n",n-MaxMatch());
	}

	return 0;
}