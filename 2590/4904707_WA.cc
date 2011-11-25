#include<math.h>
#include<stdio.h>
#define ui unsigned int
int main()
{
	ui x,y;
	ui diff;
	int time,res;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%u%u",&x,&y);
		diff = y - x;
		if(diff % 2)
		{
			if(sqrt(1.0*diff)*sqrt(1.0*diff) == diff)
				res = 2 * sqrt(diff*1.0) - 1;
			else
				res = 2 *sqrt(diff*1.0);
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