#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int v[1000000];
int main()
{
	int n,sum,now;
	while(scanf("%d",&n) && n)
	{
		memset(v,0,sizeof(v));
		sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d",&now);
			sum += now;
			v[sum] = i;
		}
		if(sum % 2 == 0 && v[sum/2])
			printf("Sam stops at position %d and Ella stops at position %d.\n",v[sum/2],v[sum/2]+1);
		else
			puts("No equal partitioning.");
	}

	return 0;
}