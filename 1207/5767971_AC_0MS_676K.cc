#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int dfs(int x)
{
	if(x == 1)
		return 1;
	if(x % 2 == 0)
		return dfs(x/2)+1;
	return dfs(x*3+1) + 1;
}
int main()
{
	int res,a,b,now;
	while(scanf("%d%d",&a,&b) == 2) {
		res = 0;
		for(int i = min(a,b),e=max(a,b); i <= e; i++){
			now = dfs(i);
			if(res < now)
				res = now;
		}
		printf("%d %d %d\n",a,b,res);
	}

	return 0;
}