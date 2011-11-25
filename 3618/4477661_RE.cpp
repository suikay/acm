#include <stdio.h>
#include <stdlib.h>
int compare(const void *p1,const void *p2)
{
	int a=abs(*(int *)p1);
	int b=abs(*(int *)p2);
	if(a > b)
		return 1;
	else 
		return -1;
}
int data[5003];
int main()
{
	int n,p,count = 0;
	int positive,negative;
	unsigned long long t,temp = 0;
	scanf("%lld%d",&t,&n);
	data[0] = 0;
	for( int i = 1 ;i <= n ;i++)
		scanf("%d",&data[i]);
	qsort(data,n + 1,sizeof(int),compare);
	positive = negative = 0;
	int last = 0;
	for( int i = 1; i <= n; i++) {
			temp += abs(last - data[i]);
			last = data[i];
		if( temp > t)
			break;
		count++;
	}
	printf("%d",count);
}




