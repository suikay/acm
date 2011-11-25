#include<stdio.h>
int arr[7],k,num[15];
void dfs(int get,int now)
{
	if((k-now) < (6-get))
		return;
	if(get == 6) {
		for(int i = 0; i < 5; i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[5]);
		return;
	}
	arr[get] = num[now];
	dfs(get+1,now+1);
	dfs(get,now+1);
}
int main()
{
	while(scanf("%d",&k) != EOF)
	{	
		for(int i = 0; i < k; i++)
			scanf("%d",&num[i]);
		dfs(0,0);
		printf("\n");
	}
	return 0;
}