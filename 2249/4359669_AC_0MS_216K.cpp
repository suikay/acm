#include <stdio.h>
int main()
{
	int m,n,i;
	long double b;
	scanf("%d%d",&m,&n);
	while(m > 0)
	{
		if ( n > m/2)
			n = m - n;
		b = 1;
		for( i = 1; i <= n; i++)
		{
			b *= ( m + 1 - i)*1.0/i;
		}
		i = (int ) b;
		printf("%d\n",i);
		scanf("%d%d",&m,&n);
	}
	return 0;
}