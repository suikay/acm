#include<math.h>
#include<stdio.h>
#define ui unsigned int
int main()
{
	ui x,y;
	ui diff,tmp;
	int time,res;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%u%u",&x,&y);
		diff = y - x;
		if(diff % 2)
		{
			tmp = (diff/2 + 1)*(diff-1)/2 + (diff+1)/2;
			res = sqrt(1.0*tmp) + 1;
		}
		else
		{
			double tmp = sqrt(4.0*diff + 1);
			if((tmp *tmp) < (4.0*diff + 1))
				tmp += 1.0;
			res = (int)tmp - 1;
		}
		printf("%d\n",res);
	}
	return 0;
}