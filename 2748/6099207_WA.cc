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
	int t,n,tmp;
	sum[0] = 0;
	arr[0] = 1;
	for(int i = 1; i <= 49151; i++) {
		arr[i] = (arr[i-1] + sum[i-1])%100000;
		sum[i] = (sum[i-1] + arr[i])%100000;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tmp = arr[n%49152];
		if(tmp >= 10000)
			putchar('0'+tmp/10000);
		if(tmp >= 1000)
			putchar('0'+tmp/1000%10);
		if(tmp >= 100)
			putchar('0'+tmp/100%10);
		if(tmp >= 10)
			putchar('0'+tmp/10%10);
		putchar('0'+tmp%10);
		putchar('\n');
	}

	return 0;
}
