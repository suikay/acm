#include <stdio.h>

int abs(int x)
{
	if (x >= 0)
	{
		return x;
	}
	return -x;
}
int main()
{
	int t, n, l, tmp;
	scanf("%d", &t);
	while( t--)
	{
		scanf("%d", &n);
		printf("Scenario #%d:\n", n);
		l = 2*n + 1;
		for (int i = 0; i < l ; i++ )
		{
			printf("slice #%d:\n", i+1);
			for (int j = 0; j < l; j++) 	
			{
				for (int k = 0; k < l ; k++ )
				{
					tmp = abs(i-n) + abs(j-n) + abs(k-n);
					if (tmp <= n)
					{
						printf("%d", tmp);
					}
					else
						putchar('.');
				}
				putchar('\n');
			}
		}
		puts("");
	}

	return 0;
}
