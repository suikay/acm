#include<vector>
#include<iostream>
using namespace std;
#define MID 100005
int dp[200100];
int s,f;
bool in[200100];
int main()
{
	int N,max(MID),_size;
	vector<int>sv;
	cin >> N;
	memset(dp,0xbf,sizeof(dp));
	dp[MID] = 0;
	sv.push_back(MID);
	for(int i = 0; i < N; i++)	{
		cin >> s >> f;
		_size = sv.size();
		for(int j = 0; j < _size; j++)	{
			if( dp[s+sv[j]] < f + dp[sv[j]])	{
				if( !in[s+sv[j]])	{
					in[s + sv[j]] = true;
					sv.push_back(s + sv[j]);
				}
				dp[s + sv[j]] = f + dp[sv[j]];
			}
		}
	}
	_size = sv.size();
	for(int i = 0; i < _size; i++)
		if(sv[i] >= MID && dp[sv[i]] >= 0 && (dp[sv[i]] + sv[i])>max)
			max = dp[sv[i]] + sv[i];
	cout << max-MID << endl;
	return 0;
}