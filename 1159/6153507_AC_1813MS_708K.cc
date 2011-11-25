#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)
const int N = 5010;
char str[N],str2[N];
short dp[2][N];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	memcpy(str2,str,sizeof(str));
	int len = strlen(str);
	reverse(str2,str2+strlen(str2));
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			if(str[i] == str2[j]) 
				dp[(i+1)&1][j+1] = max(dp[(i+1)&1][j+1],dp[i&1][j]+1);
			else
				dp[(i+1)&1][j+1] = max(dp[(i+1)&1][j+1],max(dp[i&1][j+1],dp[(i+1)&1][j]));
	printf("%d\n",len - dp[len&1][len]);


	return 0;
}
