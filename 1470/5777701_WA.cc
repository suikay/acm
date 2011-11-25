#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 1000;
int f[N],cnt[N];
bool v[N];
int dfs(int x)
{
	if(f[x] == -1 || v[x])
		return x;
	v[x] = true;
	return dfs(f[x]);
}
inline void get(char x)
{
	char ch = getchar();
	while(ch != x)
		ch = getchar();
}
int main()
{
	int m,n,x,y,now;
	scanf("%d",&m);
	memset(f,-1,sizeof(f));
	for(int i = 0; i< m; i++) {
		scanf("%d",&x);
		get(':'); get('(');
		scanf("%d",&now);
		get(')');
		for(int i = 0; i < now; i++) {
			scanf("%d",&y);
			f[y] = x;
		}
	}
	scanf("%d",&n);
	while(n--) {
		memset(v,false,sizeof(v));
		get('(');
		scanf("%d%d",&x,&y);
		get(')');
		dfs(x);
		cnt[dfs(y)]++;
	}
	for(int i = 0; i <= m; i++)
		if(cnt[i])
			printf("%d:%d\n",i,cnt[i]);

	return 0;
}