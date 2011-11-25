#include<stdio.h>
int main()
{
	int w,x,y,xsum,ysum,sum,_max;
	while(true)
	{
		xsum = ysum = sum = _max = 0;
		scanf("%d",&w);
		if(!w)
			break;
		while(true)
		{
			scanf("%d%d",&x,&y);
			if(x < 0)
				break;
			if(sum + x <= w)
			{
				sum += x;
				if(y > _max)
					_max = y;
				if(sum > xsum)
					xsum = sum;
			}
			else
			{
				sum = x;
				ysum += _max;
				_max = y;
			}
		}
		ysum += _max;
		printf("%d x %d\n",xsum,ysum);
	}
	return 0;
}