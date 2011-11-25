#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int k,a,b;
	scanf("%d",&k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d%d",&a,&b);
		if(a%2 && b%2)
			printf("Scenario #%d:\n%.2f\n\n",i,sqrt(2)-1+a*b);
		else
			printf("Scenario #%d:\n%.2f\n\n",i,a*b+0.0);
	}

	return 0;
}