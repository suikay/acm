#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int N, start, year, d, v[11], in[11];
int dp[46000];
bool input()
{
	memset(v,0,sizeof(v));
	memset(in,0,sizeof(in));
	cin >> start >> year;
	cin >> d;
	for(int i = 0; i < d; i++)	{
		cin >> v[i] >> in[i];
		v[i] /= 1000;
	}
	return true;
}
int f()
{
	int tmp,_in,_v;
	for(int i = 0; i < d; i++)	{
		tmp = 46000 - v[i];
		_v = v[i];
		_in = in[i];
		for(int j = 0; j < tmp; j++)	
			if( _in + dp[j] > dp[j + _v])
				 dp[j + _v] = _in + dp[j];
	}
	for(int i = 0; i < year; i++)	{
		int max(0);
		for(int j = 0; j <= start/1000; j++)
			if(dp[j] > max)
				max = dp[j];
		start += max;
	}
	return start;
}
int main()
{
	cin >> N;
	while(N--)	{
		input();
		cout << f() << endl;
	}
	return 0;
}