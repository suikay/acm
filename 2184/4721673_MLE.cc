#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define MID 100005
int dp[101][200100];
int s,f;
bool in[200100];
bool l(int x, int y){
	return x > y;
}
int main()
{
	int N,max,_size;
	vector<int>sv;
	while(cin >> N)	{
		sv.resize(0);
		memset(dp,0xbf,sizeof(dp));
		memset(in,false,sizeof(in));
		dp[0][MID] = 0;
		in[0] = true;
		sv.push_back(MID);
		dp[0][MID] = 0;
		for(int i = 1; i <= N; i++)	{
			cin >> s >> f;
			/*
			if(s<0)
				sort(sv.begin(),sv.end());
			else
				sort(sv.begin(),sv.end(),l);
				*/
			_size = sv.size();
			for(int j = 0; j < _size; j++)	{
				if(dp[i][sv[j]] < dp[i-1][sv[j]])
					dp[i][sv[j]] = dp[i-1][sv[j]];
				if( dp[i][s+sv[j]] < f + dp[i-1][sv[j]])	{
					if( !in[s+sv[j]])	{
						in[s + sv[j]] = true;
						sv.push_back(s + sv[j]);
					}
					dp[i][s + sv[j]] = f + dp[i-1][sv[j]];
				}
			}
		}
		_size = sv.size();
		max = MID;
		for(int i = 0; i < _size; i++)
			if(sv[i] >= MID && dp[N][sv[i]] >= 0 && (dp[N][sv[i]] + sv[i])>max)
				max = dp[N][sv[i]] + sv[i];
		cout << max-MID << endl;
	}
	return 0;
}