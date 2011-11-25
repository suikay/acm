#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
const double e = 2.7182818284590452354;
const double pi = 3.141592653589793239;
int main()
{
	int n,k;
	double res;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		if(k < 100000) {
			res = 0.0;
			for(int i = 1; i <= k; i++)
				res += log10(i);
			printf("%d\n",(int)(res+1.0+10e-5));
		}
		else
			printf("%d\n",(int)(log10(sqrt(2*pi*k)) + k*(k/e)+1.0));
	}

	return 0;
}