#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	double a[4],b[4];
	while(true)
	{
		for(int i = 0; i < 4; i++)
			if(!(cin >> a[i] >> b[i]))
				return 0;
		printf("%.3llf %.3llf\n",a[0]+a[3]-a[1],b[0]+b[3]-b[1]);
	}


	return 0;
}