#include<string.h>
#include<math.h>
#include<stdio.h>
int main()
{
	int n,m,k,last;
	char tmp[500000];
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n == -1)
			return 0;
		k = sqrt(2.0*m+0.25);
		while((k*(k-1)/2) < m)
			k++;
		last = k*(k-1)/2 - m;
		if(last == 0){
			for(int i = 1; i <= n-k; i++)
				printf("%d ",i);
			for(int i = n;i > n-k; i--)
				printf("%d ",i);
			//for(int i = n-k-1; i >= 1; i--)
			//	printf("%d ",i);
			//printf("1\n");
		}
		else{
			for(int i = 1; i < n - k + 1; i++)
				printf("%d ",i);
			printf("%d ",n - last);
			for(int i = n ; i > n - last ; i--)
				printf("%d ",i);
			for(int i =  n - last - 1; i >= n - k + 1; i--)
				printf("%d ",i);
			//printf("%d ",n-k+1);
		}
		printf("\n");
	}
	return 0;
}

