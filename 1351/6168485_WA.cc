#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
long long dp[20][16][4][2];
int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < 4; i++)
		dp[1][1<<i][i][0] = 1;
	for(int i = 2; i <= 16; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 16; k++)
				for(int l = 0; l < 4; l++)
					for(int m = 0; m < 2; m++) {
						dp[i][k|(1<<j)][j][m] += dp[i-1][k][l][m];
						if(abs(j-l) == 3 && m == 0)
							dp[i][k|(1<<j)][j][1] += dp[i-1][k][l][0];
					}
	while(scanf("%d",&n) && (n > 0))
	{
		long long res(0);
		for(int i = 0; i < 4; i++)
			res += dp[n][15][i][1];
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++)
				res += dp[n][15^(1<<i)][j][1];
		}
		cout << n << " " << res << endl;
//		printf("%d: %d\n",n,res);
	}
		

	return 0;
}
