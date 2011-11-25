#include<memory.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define M 55
#define T 44
#define NIL 999999
int is[M],m,t;
double dp[M][M];
void input()
{
	char c;
	scanf("%d%d",&m,&t);
	memset(is,0,sizeof(is));
	for(int i = 1; i <= m ;i++)	{
		cin >> c;
		if(c == '0')
			is[i] = 0;
		else if( c == 'L')
			is[i] = NIL;
		else if(c == '+')
			scanf("%d",&is[i]);
		else	{
			scanf("%d",&is[i]);
			is[i]*=-1;
		}
	}
}
double f()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1.0;
	for(int i = 0;i < t; i++)
		for(int j = 0;j <= m; j++)	{
			if(is[j+1] == NIL)
				dp[i+2][j+1] += dp[i][j]*0.5;
			else
				dp[i+1][j+1+is[j+1]] += dp[i][j]*0.5;
			if(is[j+2] == NIL)
				dp[i+2][j+2] += dp[i][j]*0.5;
			else
				dp[i+1][j+2+is[j+2]] += dp[i][j]*0.5;
		}
	double res(0);
	for(int i = 0; i <= t; i++)
		res += dp[i][m+2]+dp[i][m+1];
	return res;
}
int type(double x)
{
	if(fabs(x-0.50000)<10e-6)
		return 1;
	if(x > 0.5)
		return 0;
	return 2;
}
int main()
{
	int time;
	scanf("%d",&time);
	while(time--)	{
		input();
		double res;
		res = f();
		switch (type(res))	{
			case 1:
				printf("Push. 0.5000\n");
				break;
			case 0:
				printf("Bet for. %.4f\n",res);
				break;
			default:
				printf("Bet against. %.4f\n",res);
		}
	}
	return 0;
}
