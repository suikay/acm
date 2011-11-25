#include<stdio.h>
int main()
{
	int n,sum,t,tmp;
	scanf("%d",&n);
	while(n--)
	{
		sum = 0;
		scanf("%d",&t);
		for(int i = 0; i < t; i++){
			scanf("%d",&tmp);
			sum += tmp;
		}
		sum -= (t-1);
		printf("%d\n",sum);
	}
	return 0;
}