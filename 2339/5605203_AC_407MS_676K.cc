#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
char ori[110][110],tmp[110][110];
char e[256];
int main()
{
	int k,m,n,d;
	char en;
	scanf("%d",&k);
	e['P'] = 'S';
	e['S'] = 'R';
	e['R'] = 'P';
	while(k--)
	{
		memset(ori,0,sizeof(ori));
		scanf("%d%d%d",&m,&n,&d);
		for(int i = 1; i <= m; i++)
			cin >> (ori[i]+1);
		for(int i = 0; i < d; i++)
		{
			for(int j = 1; j <= m; j++)
				for(int k = 1; k <= n; k++) {
					en = e[ori[j][k]];
					if(ori[j-1][k] == en || ori[j+1][k] == en || 
						ori[j][k-1] == en || ori[j][k+1] == en)
						tmp[j][k] = en;
					else
						tmp[j][k] = ori[j][k];
				}
			memcpy(ori,tmp,sizeof(tmp));
		}
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++)
				printf("%c",ori[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}