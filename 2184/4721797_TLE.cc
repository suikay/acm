#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define MID 100005
int dp[2][200100];
int s,f;
bool in[200100];
bool l(int x, int y){
	return x > y;
}
int main()
{
	int N,max,_size;
	vector<int>sv;
	while(scanf("%d",&N))	{
		sv.resize(0);
		memset(dp,0xbf,sizeof(dp));
		memset(in,false,sizeof(in));
		dp[0][MID] = 0;
		in[0] = true;
		sv.push_back(MID);
		dp[0][MID] = 0;
		for(int i = 1; i <= N; i++)	{
			scanf("%d%d",&s,&f);
			_size = sv.size();
			for(int j = 0; j < _size; j++)	{
				if(dp[1][sv[j]] < dp[0][sv[j]])
					dp[1][sv[j]] = dp[0][sv[j]];
				if( dp[1][s+sv[j]] < f + dp[0][sv[j]])	{
					if( !in[s+sv[j]])	{
						in[s + sv[j]] = true;
						sv.push_back(s + sv[j]);
					}
					dp[1][s + sv[j]] = f + dp[0][sv[j]];
				}
			}
				memcpy(dp,dp[1],sizeof(int)*200100);
				memset(dp[1],0xbf,sizeof(dp)/2);
		}
		_size = sv.size();
		max = MID;
		for(int i = 0; i < _size; i++)
			if(sv[i] >= MID && dp[0][sv[i]] >= 0 && (dp[0][sv[i]] + sv[i])>max)
				max = dp[0][sv[i]] + sv[i];
		printf("%d\n",max - MID);
	}
	return 0;
}