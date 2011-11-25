#include <stdio.h>
#include <memory.h>
bool appear[100000];
int main()
{
	int dad,son,data[100000],root,count,max,i;
	scanf("%d%d",&dad,&son);
	count = 1;
	while ( dad > 0)
	{
		max = root =  0;
		memset(data,0,sizeof(data));
		memset(appear,false,sizeof(appear));
		while (dad > 0 )
		{
			data[son] ++;
			appear[dad] = true;
			scanf("%d%d",&dad,&son);
			if( dad > max ) 
				max = dad;
			if ( son > max)
				max = son;
		}
		for ( i = 0; i <= max; i++)
			if( data[i] > 1) {
				root = 2;
			}
			else
				if (appear[i] && data[i] == 0 )
				root ++;
		if (root > 1)
			printf("Case %d is a not tree.\n",count++);
		else
			printf("Case %d is a tree.\n",count++);
		scanf("%d%d",&dad,&son);
	}
	return 0;
}