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
bool dfs(int x)
{
	for(int i = 1; i <= n; i++)
		if(!v[i] && m[x][i]) {
			v[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
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
			m[i][tmp] = true;
		}
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d",&tmp);
		ori[i] = tmp;
		omatch[tmp] = i;
	}
	bool back[N];
	int res[N],pn;
	memset(check,false,sizeof(check));
	for(int i = 1; i <= n; i++) {
		pn = 0;
		memcpy(back,m[i],sizeof(back));
		memset(m[i],false,sizeof(m[i]));
		for(int j = 1; j <= n; j++)
			if(back[j]) {
				if(check[i][j]){
					res[pn++] = j;
					continue;
				}
				m[i][j] = true;
				memcpy(match,omatch,sizeof(match));
				match[ori[i]] = -1;
				memset(v,false,sizeof(v));
				if(dfs(i)) {
					res[pn++] = j;
					for(int k = 1; k <= n; k++)
						check[match[k]][k] = true;
				}
				m[i][j] = false;
			}
		sort(res,res+pn);
		printf("%d ",pn);
		for(int j = 0; j < pn-1; j++)
			printf("%d ",res[j]);
		printf("%d\n",res[pn-1]);
		memcpy(m[i],back,sizeof(back));
	}

	return 0;
}