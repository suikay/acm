#include <math.h>
#include <stdio.h>
int main()
{
	int num,sum,i,temp;
	scanf("%d",&num);
	printf("PERFECTION OUTPUT\n");
	while (num > 0)
	{
		sum = 1;
		temp = sqrt((num - 1) * 1.0);
		for ( i = 2; i <= temp ;i ++)
			if (num % i == 0)
				sum += (i + num / i);
		if ( i * i == num)
			sum += i;
		if ( sum > num)
			printf("%5d  ABUNDANT\n",num);
		else
			if( num == sum)
				printf("%5d  PERFECT\n",num);
			else
				printf("%5d  DEFICIENT\n",num);
		scanf("%d",&num);
	}
	printf("END OF OUTPUT\n");
	return 0;
}