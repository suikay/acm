#include<stdio.h>
bool num[5000001];
int count,prime[2000000],worth[20000000];;
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
	int i,j,smithNum,begin,sum=0,buffer;
	for(i=2;i<5000001;i++)
		if(!num[i]){
			for(j=2;j<=(5000001/i);j++)
				num[j*i]=true;
			prime[count]=i;
			worth[count]=f(prime[count]);
			count++;
		}
	scanf("%d",&begin);
	while(begin>0){
	for(smithNum=begin;true;smithNum++){
		buffer=smithNum;
		sum=0;
		for(i=0;i<count;i++)
			while(buffer>0&&buffer%prime[i]==0){
				sum+=worth[i];
				buffer=buffer/prime[i];
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
