#include <string.h>
#include <stdio.h>
int find(char *str, char c)
{
	for(int  i = 0 ;i < strlen(str); i++)
		if (str[i] == c)
			return i;
}
int main()
{
	char str[12];
	int i,position,sum=0;
	gets(str);
	for ( i = 0; i < 10 ; i++)
		if (str[i] == 'X' )
			sum += 10;
		else
			if (str[i] != '?')
				sum += (10 - i ) * (str[i] - '0');
	sum %= 11;
	position =10 - find(str,'?');
	for ( i = 0 ; i < 10 ; i++)
		if ((position * i  + sum)%11 == 0) {
			printf("%d",i);
			return 0;
		}
		if ( position == 1 && ((sum + 10 ) % 11 == 0)) {
			printf("X");
			return 0;
		}
	printf("-1");
	return 0;
}