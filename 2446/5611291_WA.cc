#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 33;
bool v[N][N];
int m,n,k;
bool dfs(int lx,int ly)
{
	while(v[lx][ly]) {
		ly++;
		if(ly > n) {
			lx++;
			ly = 1;
			if(lx > m)
				return true;
		}
	}
	v[lx][ly] = true;
	if(ly < n && !v[lx][ly+1]) {
		v[lx][ly+1] = true;
		if(dfs(lx,ly))
			return true;
		v[lx][ly+1] = false;
	}
	if(lx < m && !v[lx+1][ly]) {
		v[lx+1][ly] = true;
		if(dfs(lx,ly))
			return true;
		v[lx+1][ly] = false;
	}
	v[lx][ly] = false;
	return false;
}

int main()
{
	int x,y;
	scanf("%d%d%d",&m,&n,&k);
	if((m*n)%k) {
		printf("NO\n");
		return 0;
	}
	memset(v,false,sizeof(v));
	for(int i = 0; i < k; i++) {
		scanf("%d%d",&x,&y);
		v[y][x] = true;
	}
	if(dfs(1,1))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}