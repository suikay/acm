#include <stdio.h>
int two(unsigned int x)
{
	int count = 0;
	while (!( x & 1))
	{
		x = x >> 1;
		count ++;
	}
	return count;
}
int lf(unsigned int x,int pow)
{
	if ( pow == 1)
		return ( x - 1);
	return lf( x - (1 << (pow - 1)),pow - 1);
}
int rf(unsigned int x ,int pow)
{
	if ( pow == 1)
		return (x + 1);
	return rf( x + (1 << (pow - 1)),pow - 1);
}
int  main()
{
	unsigned int x;
	int num,temp;
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d",&x);
		if ( (x % 2) == 1)
			printf("%d %d\n",x,x);
		else
		{
			temp = two(x);
			printf("%d %d\n",lf(x,temp),rf(x,temp ));
		}
	}
	return 0;
}
