#include<stdio.h>
int main()
{
	int op,res,s,e;
	while(true)
	{
		scanf("%d%d",&res,&op);
		if(!res && !op)
			return 0;
		res++;
		while(op--)
		{
			scanf("%d%d",&s,&e);
			res -= (e - s + 1);
		}
		printf("%d\n",res);
	}
	return 0;
}