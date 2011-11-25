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
		double aa,bb;
		aa = bb = 0;
		for(int i = 0; i < 4; i++) {
			if((scanf("%lf%lf",&a[i],&b[i]))!=2)
				return 0;
			else {
				aa += a[i];
				bb += b[i];
			}
		}
		if(a[0] == a[2] && b[0] == b[2]) {
			aa -= 3*a[0];
			bb -= 3*b[0];
		} else 
			if(a[0] == a[3] && b[0] == b[3]) {
			aa -= 3*a[0];
			bb -= 3*b[0];
		} else {
			aa -= 3*a[1];
			bb -= 3*b[1];
		}
		printf("%.3lf %.3lf\n",aa,bb);
	}

	return 0;
}