#include <math.h>
#include <stdio.h>
int main()
{
	int b,n;
	double res;
	while( scanf("%d%d",&b,&n) == 2) {
		if(!b)
			break;
		res = exp(log(b * 1.0) / n);
		int t1 = exp(n * log((int)res * 1.0));
		int t2 = exp(n * log((int)res + 1.0));
		t1 = abs(t1 - b);
		t2 = abs(t2 - b);
		printf("%d\n",t1 > t2 ? (int)res + 1:(int)res);
	}
}