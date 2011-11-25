#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int arr[1050],t,n,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		while(p--)
			if(!next_permutation(arr,arr+n))
				break;
		for(int i = 0; i < n-1; i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}