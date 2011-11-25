#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int n,d,k,res,cow[1100];
void dfs(int s,int use,int now)
{
	if(use > k)
		return;
	if(now > d) {
		if(use != k)
			return;
		int cnt = 0;
		for(int i = 0; i < n; i++) 
			if(((s ^ cow[i]) + cow[i]) == s)
				cnt++;
		if(cnt > res)
			res = cnt;
		return;
	}
	dfs(s|(1 << now),use+1,now+1);
	dfs(s,use,now+1);
}

int main()
{
	int tmp,t,p;
	scanf("%d%d%d",&n,&d,&k);
	for(int i = 0; i < n; i++) {
		tmp = 0;
		scanf("%d",&t);
		for(int j = 0; j < t; j++) {
			scanf("%d",&p);
			tmp |= (1 << p);
		}
		cow[i] = tmp;
	}
	res = 0;
	dfs(0,0,1);
	printf("%d\n",res);

	return 0;
}