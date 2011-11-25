#include <stdio.h>
#include <memory.h>
bool appear[100000];
int main()
{
	int dad,son,parent[100000],root,count,max,i,flag,temp;
	scanf("%d%d",&dad,&son);
	count = 1;
	while ( dad > 0)
	{
		max = root =  0;
		flag = true;
		memset(parent,0,sizeof(parent));
		memset(appear,false,sizeof(appear));
		while (dad > 0 )
		{
			if ( parent[son] > 0 || son == dad) 
				flag = false;
			parent[ son ] = dad;
			scanf("%d%d",&dad,&son);
			if( dad > max ) 
				max = dad;
			if ( son > max)
				max = son;
		}
		for ( i = 0; i <= max; i++) {
			if (parent[i]) {
				temp = i;
				while ( temp != root || !root)
					if (parent[temp]) {
						temp = parent[temp];
						if (temp == i) {
							flag = false;
							break;
						}
					}
					else
						break;
				if (!root)
					root = temp;
				else
					if (temp != root) {
						flag = false;
						break;
					}
			}
		}
		if (!flag)
			printf("Case %d is not a tree.\n",count++);
		else
			printf("Case %d is a tree.\n",count++);
		scanf("%d%d",&dad,&son);
	}
	return 0;
}