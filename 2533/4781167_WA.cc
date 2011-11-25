#include<stdio.h>
int main()
{
	int dp[1010],m,res(0);
	int n,arr[1010];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		m = 0;
		for(int j = 0; j < i; j++)
			if(arr[j] < arr[i] && dp[j] > m)
				m = dp[j];
		dp[i] = m+1;
		if((m+1) > res)
			res = m+1;
	}
	printf("%d\n",res);
	return 0;
}