#include <stdio.h>
#include <string.h>
int data[256];
int main()
{
	int i,j,right,max = 0 ,count = 0;
	char c;
	while( scanf("%c",&c) == 1 && count < 3) {
		if ( c == '\n')
			count ++;
		data[c] ++;
	}
	for( i = 'A'; i < 'Z';i++)
		if(data[i] > max)
			max = data[i];
	for( i = max; i >= 0; i--)
	{
		for( j = 'Z'; j >= 'A'; j--)
			if( data[j] >= i) {
				right = j;
				break;
			}
		for( j = 'A'; j <= 'Z'; j++)
			if( data[j] <= i)
				printf(" %s",j < 'Z'? " ":"\n");
			else
				printf("*%s",j < 'Z'? " ":"\n");
	}
	for( i = 'A'; i <= 'Z';i ++)
		printf("%c%s",i,i < 'Z'? " ":"");
}