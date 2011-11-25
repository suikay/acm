#include <stdio.h>
int data[10005];
int main()
{
	int num,i,a,b,max,maxi;
	max = 0;
	scanf("%d",&num);
	for ( i = 0 ; i < num; i++)
	{
		scanf("%d%d",&a,&b);
		for ( ; a <= b; a++)
			data[a]++;
	}
	for ( i = 0; i <= 10000; i++)
		if (data[i] >max)
		{
			max = data[i];
			maxi = i;
		}
		printf("%d\n",maxi);
		return 0;
}