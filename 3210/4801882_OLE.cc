#include<stdio.h>
int main()
{
	int x;
	while(scanf("%d",&x))
		if(x%2)
			printf("%d\n",x/2);
		else
			printf("No Solution!\n");
	return 0;
}