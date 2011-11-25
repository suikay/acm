#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int MAXN = 1000;
int uN, vN;
bool g[MAXN][MAXN];
bool bad[10][10];
int xM[MAXN],yM[MAXN];
bool chk[MAXN];
bool SearchPath(int u) {
	int v;
	for(v = 0; v < vN; v++)
		if(g[u][v] && !chk[v])
		{
			chk[v] = true;
			if(yM[v] == -1 || SearchPath(yM[v]))
			{
				yM[v] = u; xM[u] = v;
				return true;
			}
		}
	return false;
}
int MaxMatch() {
	int u, ret = 0;
	memset(xM, -1, sizeof(xM));
	memset(yM, -1, sizeof(yM));
	for(u = 0; u < uN; u++)
		if(xM[u] == -1) {
			memset(chk, false,sizeof(chk));
			if(SearchPath(u))
				ret++;
		}
	return ret;
}
int main()
{
	int t,x1,y1,x2,y2;
	scanf("%d",&t);
	for(int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		memset(bad,false,sizeof(bad));
		memset(g,false,sizeof(g));
		bad[x1-1][y1-1] = bad[x2-1][y2-1] = true;
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				if(!bad[i][j])
					for(int k = i-1; k <= i+1; k++)
						for(int l = j-1; l <= j+1; l++)
							if((k+l-i-j == 1) && (k >= 0 && k < 8) && (l >= 0 && l < 8) && (i != k || j != l) && !bad[k][l])
								g[i*8+j][k*8+l] = g[k*8+l][i*8+j] = true;
		uN = vN = 64;
		printf("Scenario #%d:\n",tt);
//		printf("%d\n",MaxMatch());
		if(MaxMatch() == 62)
			puts("1");
		else
			puts("0");
		puts("");
	}


	return 0;
}
