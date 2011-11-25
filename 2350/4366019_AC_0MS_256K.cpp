#include <stdio.h>
int main()
{
	int data[10000];
	int tnum,snum,count,sum,i,j;
	scanf("%d",&tnum);
	for ( i = 0 ; i < tnum; i ++)
	{
		scanf("%d",&snum);
		sum = 0;
		for ( j = 0; j < snum; j++)
		{
			scanf("%d",&data[j]);
			sum += data[j];
		}
		sum /= snum;
		count = 0;
		for ( j = 0 ; j < snum; j++)
			if ( data[j] > sum)
				count ++;
		printf("%2.3f%%\n",count*100.0/snum);
	}
	return 0;
}