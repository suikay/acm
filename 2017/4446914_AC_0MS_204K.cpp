#include <stdio.h>
int main()
{
	int n;
	int last,s,t,sum;
	scanf("%d",&n);
	while ( n != -1)
	{
		sum = last = 0;
		for( int i = 0; i < n;i++)
		{
			scanf("%d%d",&s,&t);
			sum += s * ( t - last );
			last = t;
		}
		printf("%d miles\n",sum);
		scanf("%d",&n);
	}
}