#include<stdio.h>
int one[181]={0};
int main()
{
	one[0]=1;
	for(int i=1; i<21; i++)
		for(int j=1; j<=3; j++)
			one[i*j]++;
	one[25]++;
	one[50]++;
	int n,res,num;
	scanf("%d",&n);
	for(int i=1; i<= n; i++) {
		scanf("%d",&num);
		res=0;
		for(int j=(num+2)/3; j<=num; j++)
			for(int k=j; k>=0; k--)
				if((num-j-k)>k||(num-j-k)<0)
					continue;
				else
					res+=one[j]*one[k]*one[num-j-k];
		printf("Scenario #%d:\n%d\n\n",i,res);
	}
	return 0;
}

