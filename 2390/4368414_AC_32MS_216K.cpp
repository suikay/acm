#include <stdio.h>
int main()
{
	double sum,dr;
	int r,m,y,i;
	scanf("%d%d%d",&r,&m,&y);
	dr =  1 + r * 1.0 / 100;
	sum = m;
	for ( i = 0; i < y; i ++)
		sum *= dr;
	m = sum;
	printf("%d",m);
	return 0;
}
