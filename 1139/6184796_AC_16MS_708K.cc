#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 110;
bool cat[N][N],mouse[N][N],orim[N][N],v[N];
int r,oc,om;
bool dfs(int x,int dep)
{
	if(x == om && dep) {
		if(dep >= 2)
			return true;
		else
			return false;
	}
	for(int i = 1; i <= r; i++)
		if(orim[x][i] && !v[i] && !cat[oc][i]) {
			v[i] = true;
			if(dfs(i,dep+1))
				return true;
			v[i] = false;
		}
	return false;
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(cat,false,sizeof(cat));
		memset(mouse,false,sizeof(mouse));
		scanf("%d%d%d",&r,&oc,&om);
		while(scanf("%d%d",&m,&n) && m >= 0)
			cat[m][n] = true;
		//memcpy(oric,cat,sizeof(cat));
		while(scanf("%d%d",&m,&n) && m >= 0)
			mouse[m][n] = true;
		memcpy(orim,mouse,sizeof(mouse));
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= r; j++)
				for(int k = 1; k <= r; k++)
					cat[j][k] |= (cat[j][i] & cat[i][k]);
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= r; j++)
				for(int k = 1; k <= r; k++)
					mouse[j][k] |= (mouse[j][i] & mouse[i][k]);
		bool r1(false),r2(false);
		for(int i = 1; i <= r; i++)
			if(cat[oc][i] && mouse[om][i])
				r1 = true;
		memset(v,false,sizeof(v));
		if(dfs(om,0))
			r2 = true;
		printf("%c %c\n",r1?'Y':'N',r2?'Y':'N');
	}



	return 0;
}

/*
1

5 2 4
1 2
2 1
3 1
4 3
2 5
-1 -1
1 3
2 5
3 4
4 1
4 2
4 5
5 4
-1 -1
*/
