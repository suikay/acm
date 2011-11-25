#include<stdio.h>
bool num[5000001];
int count,prime[2000000],worth[20000000];;
int f(int x)
{
	int sum=0;
	if(x<10)
		return x;
	while(x>0){
		sum+=x%10;
		x=x/10;
	}
	return sum;
}
int main()
{
	int i,j,smithNum,begin,sum=0,buffer;
	for(i=2;i<5000001;i++)
		if(!num[i]){
			for(j=i+i;j<=5000001;j+=i)
				num[j]=true;
			prime[count++]=i;
		}
	scanf("%d",&begin);
	while(begin>0){
	for(smithNum=begin;true;smithNum++){
		buffer=smithNum;
		sum=0;
		for(i=0;i<count;i++)
			while(buffer%prime[i]==0){
				sum+=f(prime[i]);
				buffer=buffer/prime[i];
				if(buffer==0)
					i=count;
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
