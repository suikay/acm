#include<memory.h>
#include<iostream>
#define SQ(x) (x)*(x)
#define MAX 250
using namespace std;
int main()
{
	int dp[MAX][MAX];
	int color[MAX];
	int count[MAX];
	int m,n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		memset(dp,0,sizeof(dp));
		memset(color,0,sizeof(color));
		memset(count,0,sizeof(count));
		cin >> m;
		int index = 0,tmp;
		for(int j = 0; j < m; j++)	{
			cin >> tmp;
			if(color[index] == tmp)
				count[index]++;
			else	{
				color[++index] = tmp;
				count[index] = 1;
			}
		}
		for(int j = 1; j <= index; j++)
			dp[j][j] = count[j]*count[j];
		for(int j = 1; j < index; j++)
			for(int k = 1; k + j <= index; k++)
				if(color[k] == color[j+k])
					dp[k][j+k] = max(dp[k][j+k],dp[k+1][k+j-1]+SQ(count[k]+count[j+k]));
				else
					dp[k][j+k] = max(dp[k][j+k],max(dp[k][k]+dp[k+1][k+j],dp[k][k+j-1]+dp[k+j][k+j]));
		cout << "Case " << i << ": " << dp[1][index] << endl;
	}
	return 0;
}
