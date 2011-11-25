#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 310;
const int INF = 0x7f7f7f7f;
int hit[N][N],res;
void dfs(int x,int y,int t)
{
	if(x < 0 || y < 0 || t >= res)
		return;
	if(hit[x][y] <= t)
		return;
	if(hit[x][y] == INF ) {
		if(res > t)
			res = t;
		return;
	}
	++t;
	dfs(x+1,y,t);
	dfs(x,y+1,t);
	dfs(x-1,y,t);
	dfs(x,y-1,t);
}
int main()
{
	int m,x,y,t;
	scanf("%d",&m);
	memset(hit,0x7f,sizeof(hit));
	res = INF;
	for(int i = 0; i < m; i++) 
	{
		scanf("%d%d%d",&x,&y,&t);
		if(hit[x][y] > t)
			hit[x][y] = t;
		if(x > 0 && hit[x-1][y] > t)
			hit[x-1][y] = t;
		if(y > 0 && hit[x][y-1] > t)
			hit[x][y-1] = t;
		if(hit[x+1][y] > t)
			hit[x+1][y] = t;
		if(hit[x][y+1] > t)
			hit[x][y+1] = t;
	}
	dfs(0,0,0);
	if(res == INF)
		cout << -1 << endl;
	else
		cout << res << endl;

	return 0;
}