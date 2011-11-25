#include<stdio.h>
int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
		if(x%2)
			printf("%d\n",x-1);
		else
			printf("No Solution!\n");
	return 0;
}