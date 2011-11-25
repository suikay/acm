#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
int w,h,rec[40];
bool v[40];
bool dfs(int x,int y,int last)
{
	if(x > h || x <= 0 || y > w || y <= 0)
		return false;
	if(last == 0)
		return true;
	for(int i = 0; i < 8; i++) {
		int tx = x+dx[i];
		int ty = y+dy[i];
		int tmp = tx*w+ty;
		if(tx > 0 && ty > 0 && !v[tmp]) {
			rec[last] = tmp;
			v[tmp] = true;
			if(dfs(tx,ty,last-1))
				return true;
			v[tmp] = false;
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) 
	{
		memset(v,false,sizeof(v));
		scanf("%d%d",&w,&h);
		rec[w*h] = w+1;
		v[w+1] = true;
		printf("Scenario #%d:\n",i);
		if(dfs(1,1,w*h-1)) {
			for(int i = w*h; i > 0; i--)
				printf("%c%d",(rec[i]-1)/w+'A'-1,(rec[i]-1)%w+1);
			printf("\n\n");
		}
		else
			printf("impossible\n\n");
	}
	return 0;
}