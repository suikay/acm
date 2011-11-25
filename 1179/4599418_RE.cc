#include<stdio.h>
#include<iostream>
using namespace std;
#define N 55
#define NIL 99999999
int ff(int x,int y,char z)	{
	if(z == 'x')
		return x*y;
	return x+y;
}
int dp[N][N],ndp[N][N],num[N];
char o[N];
int main()
{	
	int n;
	cin >> n;
	/*
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)	{
			dp[i][j] = -NIL;
			ndp[i][j] = NIL;
		}
		*/
	for(int i = 0; i < n; i++)	{
		cin >> o[i] >> num[i];
		o[i+n]=o[i];
		num[i+n] = num[i];
		dp[i][i] = dp[i+n][i+n] = num[i];
		ndp[i][i] = ndp[i+n][i+n] = num[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 2*n - i; j++){
			int tmp = ff(dp[j][j],dp[j+1][j+i],o[j+1]);
			dp[j][j+i] = tmp;
			ndp[j][j+i] = tmp;
			for(int k = j+1; k < j+i; k++)	{
			tmp = ff(ndp[j][k],ndp[k+1][j+i],o[k+1]);
			if(tmp > dp[j][j+i])
				dp[j][j+i] = tmp;
			if(tmp < ndp[j][j+i])
				ndp[j][j+i] = tmp;
			tmp = ff(ndp[j][k],dp[k+1][j+i],o[k+1]);
			if(tmp > dp[j][j+i])
				dp[j][j+i] = tmp;
			if(tmp < ndp[j][j+i])
				ndp[j][j+i] = tmp;
			tmp = ff(dp[j][k],ndp[k+1][j+i],o[k+1]);
			if(tmp > dp[j][j+i])
				dp[j][j+i] = tmp;
			if(tmp < ndp[j][j+i])
				ndp[j][j+i] = tmp;
			}
		}
	int top(0),queue[N],max(-NIL);
	for(int i = 0; i < n; i++)
		if(max == dp[i][i+n-1])
			queue[top++] = i+1;
		else if(max < dp[i][i+n-1])	{
			max = dp[i][i+n-1];
			top = 0;
			queue[top++] = i+1;
		}
	printf("%d\n",max);
	for(int i = 0; i < top; i++)
		printf("%d%c",queue[i],(i<top-1)?' ':'\n');
	return 0;
}