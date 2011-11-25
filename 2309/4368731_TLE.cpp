#include <stdio.h>
int two(int x)
{
	int count = 0;
	while (!( x & 1))
	{
		x = x >> 1;
		count ++;
	}
	return count;
}
int twopow(int x)
{
	int count = 1;
	count <<= x;
	return count;
}
int lf(int x)
{
	int temp = two(x);
	if ( temp == 1)
		return ( x - 1);
	return lf( x - (1 << (temp - 1)));
}
int rf(int x)
{
	int temp = two(x) ;
	if ( temp == 1)
		return (x + 1);
	return rf( x + (1 << (temp - 1)));
}
int  main()
{
	int num,x;
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d",&x);
		printf("%d %d\n",lf(x),rf(x));
	}
	return 0;
}
