#include<stdio.h>
int main()
{
	int arr[70000];
	for(int i = 2; i <= 65536; i+=2){
		arr[i] = i/2*(1+i);
		arr[i+1] = (i+2)/2*(i+1);
	}
	int n,dummy,t,res;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		res = 0;
		scanf("%d%d",&dummy,&t);
		for(int j = 2; j <= 65536; j++)
			if(arr[j] > t)
				break;
			else
				if((t-arr[j])%j==0)
					res++;
		printf("%d %d\n",i,res);
	}
	return 0;
}