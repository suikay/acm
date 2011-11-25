#include<stdio.h>
#include<math.h>
int f(int x)
{
	int sum=0;
	while(x>0){
		sum+=x%10;
		x=x/10;
	}
	return sum;
}
int main()
{
	int i,j,begin,buffer,smithNum,sum;
	scanf("%d",&begin);
	while (begin){
		for(smithNum=begin;true;smithNum++){
			buffer=smithNum;
			sum=0;
			for(i=2;i<=smithNum;i++)
				while(buffer%i==0)
				{
					sum+=f(i);
					buffer=buffer/i;
					if (buffer==1)
						i=99999999;
				}
				if (sum==f(smithNum)){
					printf("%d\n",smithNum);
					break;
				}
		}
		scanf("%d",&begin);
	}
	return 0;
}
