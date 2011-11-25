#include <memory.h>
#include <stdio.h>
int list[15],mark[300];
int main()
{
	int times,count,temp = 0,i;
	while ( temp >= 0)
	{
		times = count = 0;
		memset(mark,0,sizeof(mark));
		scanf("%d",&temp);
		while ( temp > 0)
		{
			mark[temp] = 1;
			list[count++] = temp;
			scanf("%d",&temp);
		}
		for( i = 0; i < count; i++)
			if (mark[list[i] * 2])
				times ++;
		printf("%d\n",times);
	}
	return 0;
}
