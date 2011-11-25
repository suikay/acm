#include <stdio.h>
#include <string.h>
int data[256];
int main()
{
	int i,j,right,max = 0 ,count = 0;
	char c;
	freopen("out.txt","w",stdout);
	while( count <= 3) {
		scanf("%c",&c) ;
		if ( c == '\n')
			count ++;
		data[c] ++;
	}
	for( i = 'A'; i < 'Z';i++)
		if(data[i] > max)
			max = data[i];
	for( i = max; i > 0; i--)
	{
		for( j = 'Z'; j >= 'A'; j--)
			if( data[j] >= i) {
				right = j;
				break;
			}
		for( j = 'A'; j <= right; j++)
			if( data[j] < i)
				printf(" %s",j < right? " ":"\n");
			else
				printf("*%s",j < right? " ":"\n");
	}
	for( i = 'A'; i <= 'Z';i ++)
		printf("%c%s",i,i < 'Z'? " ":"");
}