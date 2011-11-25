#include<algorithm>
using namespace std;
#include<stdio.h>
int main()
{
	int n,f,need;
	int arr[11000];
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d",&need,&f);
		for(int j = 0;j < f; j++)
			scanf("%d",&arr[j]);
		sort(arr,arr+f);
		int p = f;
		while(p > 0 && need > 0)
			need -= arr[--p];
		if(need > 0)
			printf("Scenario #%d:\nimpossible\n\n",i);
		else
			printf("Scenario #%d:\n%d\n\n",i,f-p);
	}
	return 0;
}
