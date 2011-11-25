#include <stdio.h>
int hi[100],n;
int main()
{
	int i,j,aver,k,sum,count = 1;
	scanf("%d",&n);
	while ( n > 0) {
		sum = 0;
		k = 0;
		for( i = 0; i < n; i++)
		{
			scanf("%d",&hi[i]);
			sum += hi[i];
		}
		aver = sum / n;
		for ( i = 0; i < n; i++)
			if(hi[i] > aver)
				k += hi[i] - aver;
			else
				k += aver - hi[i];
		printf("Set #%d\n",count++);
		printf("The minimum number of moves is %d.\n",k/2);
		scanf("%d",&n);
	}
	return 0;
}