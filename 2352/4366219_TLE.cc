#include <stdio.h>
#include <memory.h>
int data[2][32002];
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
			for( i = lastx ; i <= x ;i++)
				data[1][i] = left;
			data[1][x] =left+ 1;
			count[data[1][x] - 1]++;
			lastx = x;
			left++;
		}
		else
		{
			for( i = 0;i <= lastx; i ++)
				data[0][i] = data[1][i];
			for( i = lastx; i < 32002; i++)
				data[0][i] += left;
			for( i = 0; i <= x; i++)
				data[1][i] = data[0][i];
			data[1][x] =data[0][x]+1;
			count[data[1][x]-1]++;
			lastx = x;
			lasty = y;
			left = 1;
		}
	}
	for ( i = 0; i < num;i ++)
		printf("%d\n",count[i]);
	return 0;
}