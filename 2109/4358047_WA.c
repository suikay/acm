#include <stdio.h>
#include <math.h>
int main()
{
	float n,p;
	while(scanf("%lf%lf",&n,&p)==2)
		printf("%.0lf\n",pow(p,1.0/n));
	return 0;
}