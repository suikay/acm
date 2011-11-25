#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 410;
int match[N],m,n;
bool check[N],net[N][N];
bool dfs(int x)
{
	for(int i = 1; i <= n; i++)
		if(!check[i] && net[x][i]) {
			check[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
			}
	}
	return false;
}

int maxmatch()
{
	int res(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= m; i++) {
		memset(check,false,sizeof(check));
		if(dfs(i)) {
			res++;
		}
	}
	return res;
}

int main()
{
	int t,tmp;
	memset(net,false,sizeof(net));
	scanf("%d%d",&m,&n);
	for(int i = 1; i <= m; i++) {
		scanf("%d",&t);
		for(int j = 0; j < t; j++) {
			scanf("%d",&tmp);
			net[i][tmp] = true;
		}
	}
	printf("%d\n",maxmatch());

	return 0;
}
