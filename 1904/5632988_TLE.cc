#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 2100;
bool m[N][N],v[N],check[N][N];
int match[N],n,omatch[N];
int next[N][N],cnt[N];
bool dfs(int x)
{
	static int i;
	for(int k = 0; k < cnt[x]; k++) {
		i = next[x][k];
		if(!v[i]) {
			v[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}


int main()
{
	int k,tmp;
	int ori[N];
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&k);
		for(int j = 0; j < k; j++) {
			scanf("%d",&tmp);
			next[i][j] = tmp;
		}
		cnt[i] = k;
	}
	memset(check,false,sizeof(check));
	for(int i = 1; i <= n; i++) {
		scanf("%d",&tmp);
		ori[i] = tmp;
		omatch[tmp] = i;
		check[i][tmp] = true;
	}
	bool back[N];
	int res[N],pn,j;
	for(int i = 1; i <= n; i++) {
		pn = 0;
		for(int k = 0; k < cnt[i]; k++) {
			j = next[i][k];
			if(check[i][j]){
				res[pn++] = j;
				continue;
			}
			memcpy(match,omatch,sizeof(match));
			match[ori[i]] = -1;
			memset(v,false,sizeof(v));
			v[j] = true;
			tmp = match[j];
			match[j] = i;
			match[ori[i]] = -1;
			if(dfs(tmp)) {
				res[pn++] = j;
				for(int i = 1; i <= n; i++) 
					check[match[i]][i] = true;
			}
		}
		sort(res,res+pn);
		printf("%d ",pn);
		for(int j = 0; j < pn-1; j++)
			printf("%d ",res[j]);
		printf("%d\n",res[pn-1]);
	}

	return 0;
}