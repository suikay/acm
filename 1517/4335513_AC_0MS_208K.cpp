#include <stdio.h>
int main()
{
	int n,i = 1;
	double e = 1;
	printf("n e\n");
	printf("- -----------\n");
	for ( n = 0; n <= 9; n++)
	{
		if ( n < 2)
			printf("%d %1.0f\n",n,e);
		else
			if( n == 2)
				printf("%d %1.1f\n",n,e);
			else
				printf("%d %.9f\n",n,e);
		i *= (n + 1);
		e += 1 / ( i * 1.0);
	}
	return 0;
}
