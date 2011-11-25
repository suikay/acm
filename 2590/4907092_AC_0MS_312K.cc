#include<math.h>
#include<stdio.h>
#define max(a,b) a>b?a:b
#define ui unsigned int
int main()
{
	ui x,y;
	ui diff,tmp;
	ui time,res;
	scanf("%u",&time);
	while(time--)
	{
		scanf("%u%u",&x,&y);
		diff = y - x;
		for(ui i = max(0,sqrt(4.0*diff)-1); ;i++)
			if(i%2)
			{
				if((i+1)/2*((i+1)/2) >= diff){
					res = i;
					break;
				}
			}
			else
			{
				if((i/2*(i/2) + i/2) >= diff){
					res = i;
					break;
				}
			}
		printf("%d\n",res);
	}
	return 0;
}