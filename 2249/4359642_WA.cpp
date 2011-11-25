#include <stdio.h>
int main()
{
	int m,n,i;
	long long a,b;
	scanf("%d%d",&m,&n);
	while(m > 0)
	{
		if ( n > m/2)
			n = m - n;
		a = b = 1;
		for( i = 1; i <= n; i++)
		{
			a *= i ;
			b *= ( m + 1 - i);
		}
		b /= a;
		printf("%d\n",b);
		scanf("%d%d",&m,&n);
	}
	return 0;
}