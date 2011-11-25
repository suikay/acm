#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	unsigned int m,a,k;
	scanf("%d",&a);
	k = a*a+1;
	for(m = a+1; m >= 1; m--)
		if(k % m == 0)
			break;
	printf("%d\n",2*a+m+k/m);

	return 0;
}
