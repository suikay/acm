#include<iostream>
using namespace std;
#define MID 100050
bool in[200100];
int dp[200100];
int main()
{
	int N,maxx,minn,s,f;
	while(scanf("%d",&N)!=EOF)	{
		memset(dp,0xbf,sizeof(dp));
		dp[MID] = 0;
		in[MID] = true;
		maxx = minn = MID;
		for(int i = 0; i < N; i++){
			scanf("%d%d",&s,&f);
			if(s < 0)	{
				for(int i = minn; i <= maxx; i++)
					if(in[i] &&(dp[i] + f > dp[i+s]))	{
						dp[i+s] = dp[i] + f;
						in[i+s] = true;
					}
				minn += s;
			}
			else	{
				for(int i = maxx; i >= minn; i--)
					if(in[i] &&(dp[i] + f > dp[i+s]))	{
						dp[i+s] = dp[i] + f;
						in[i+s] = true;
					}
				maxx += s;
			}
		}
		int res(MID);
		for(int i = MID; i <= maxx; i++)
			if(dp[i] < 0)
				continue;
			else
				if(res < (i + dp[i]))
					res = i + dp[i];
		printf("%d\n",res - MID);
	}
	return 0;
}