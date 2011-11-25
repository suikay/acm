#include <stdio.h>
long reserse(long a)
{
	long temp = 0;
	while ( a > 0)
	{
		temp = temp * 10 + a % 10;
		a /= 10;
	}
	return temp;
}
int main()
{
	long a,b,num;
	scanf("%d",&num);
	for ( int i = 0; i < num ; i++) {
		scanf("%d%d",&a,&b);
		printf("%d\n",reserse(reserse(a)+reserse(b)));
	}
	return 0;
}