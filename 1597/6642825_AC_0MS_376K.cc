#include <stdio.h>
int gcd(int x, int y)
{
	if(!(x%y))
		return y;
	return gcd(y,x%y);
}
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y) == 2)
	{
		printf("%10d%10d",x,y);
		if(( (x >= y) && (gcd(x,y) == 1)) || ((x < y) && (1 == gcd(y,x))))
		{
			puts("    Good Choice");
		} else
			puts("    Bad Choice");
		puts("");
	}
	return 0;
}
