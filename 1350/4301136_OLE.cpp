#include <stdio.h>
int bigMake(int a)
{	
	int num[4],i,j,temp,out,position = 0;
	for( i = 3; i  >= 0; i --){
		num[i] = a % 10;
		a /= 10;
	}
	while(!num[position])
		position++;
	for( i = position; i < 3 ; i++)
		for ( j = i+1; j < 4; j++)
			if (num[i] < num[j]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
	out = num[0]*1000+num[1]*100+num[2]*10+num[3];
	return out;
}
int smallMake(int a)
{	
	int num[4],i,j,temp,out,position = 0;
	for( i = 3; i  >= 0; i --){
		num[i] = a % 10;
		a /= 10;
	}
	while(!num[position])
		position++;
	for( i = position; i < 4 ; i++)
		for ( j = i+1; j < 4; j++)
			if (num[i] > num[j]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
	out = num[0]*1000+num[1]*100+num[2]*10+num[3];
	return out;
}

int main()
{
	int num,count,big,small;
	scanf("%d",&num);
	while (num > 0)
	{
		printf("N=%d:\n",num);
		count = 1;
		while ( true)
		{
			big = bigMake(num);
			small = smallMake(num);
			if (big == small && big > 1000) {
				printf("No!!\n");
				break;
			}
			num = big - small;
			printf("%d-%d=%d\n",big , small , num);
			if ( num == 0 || num == 6174) {
				printf("Ok!! %d times\n",count);
				break;
			}
			count ++;
		}
		scanf("%d",&num);
	}
	return 0;
}