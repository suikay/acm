#include<math.h>
#include<stdio.h>
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
		for(ui i = sqrt(diff*4.0) - 1; ;i++)
			if(i%2)
			{
				if((i+1)*(i+1)/4 >= diff){
					res = i;
					break;
				}
			}
			else
			{
				if((i*i/4 + i/2) >= diff){
					res = i;
					break;
				}
			}
		printf("%d\n",res);
	}
	return 0;
}