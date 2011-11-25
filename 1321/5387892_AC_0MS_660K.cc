/*
ID: immozer1
PROG: ****
LANG: C++
*/
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
#include <cstring>

using namespace std;
int res,n,k;
char m[8][8];
bool v[8];
void dfs(int row,int now,int last)
{
	if(last == 0) {
		res++;
		return;
	}
	if(now > last)
		dfs(row+1,now-1,last);
	for(int i = 0; i < n; i++) 
		if(!v[i] && m[row][i] == '#') {
			v[i] = true;
			dfs(row+1,now-1,last-1);
			v[i] = false;
		}
}
	
int main()
{
	while(scanf("%d%d",&n,&k)) 
	{
		if(n < 0)
			return 0;
		for(int i = 0; i < n; i++) 
			scanf("%s",m[i]);
		memset(v,false,sizeof(v));
		res = 0;
		dfs(0,n,k);
		printf("%d\n",res);
	}
	return 0;
}