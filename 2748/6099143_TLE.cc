#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;
short arr[50000];
short sum[50000];
int main()
{
	sum[0] = 0;
	arr[0] = 1;
	for(int i = 1; i <= 49151; i++) {
		arr[i] = (arr[i-1] + sum[i-1])%100000;
		sum[i] = (sum[i-1] + arr[i])%100000;
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",arr[n%49152]);
	}

	return 0;
}
