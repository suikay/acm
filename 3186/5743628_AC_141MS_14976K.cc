#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int dp[2100][2100],arr[2100],s[2100];
int DP(int l,int r)
{
	if(dp[l][r])
		return dp[l][r];
	dp[l][r] = max(DP(l+1,r),DP(l,r-1))+s[r]-s[l-1];
	return dp[l][r];
}
int main()
{
	int n,res(0);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d",arr+i);
		dp[i][i] = arr[i];
		if(i)
			s[i] = s[i-1]+arr[i];
		else
			s[i] = arr[i];
	}

	printf("%d\n",DP(1,n));

	return 0;
}