#include <stdio.h>
#include <memory.h>
int data[32002];
int count[15005];
int main()
{
	int num,i,j,lastx,lasty,x,y,left;
	scanf("%d",&num);
	lasty = 0;
	lastx = 0;
	left = 0;
	for ( j = 0; j < num ; j ++)
	{
		scanf("%d%d",&x,&y);
		if ( y == lasty)
		{
			for ( i = lastx; i <= x;i ++)
				data[i] = data[lastx];
			data[x] ++;
			count[data[x] - 1]++;
			lastx = x;
			left++;
		}
		else
		{
			for( i = lastx; i < 32002; i++)
				data[i] += left;
			data[x] =data[x]+1;
			count[data[x]-1]++;
			lastx = x;
			lasty = y;
			left = 1;
		}
	}
	for ( i = 0; i < num;i ++)
		printf("%d\n",count[i]);
	return 0;
}