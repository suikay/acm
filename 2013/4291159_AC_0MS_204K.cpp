#include<stdio.h>
int main()
{
	char str[15][26];
	int num,i,flag=1;
	scanf("%d",&num);
	while ( num) {
		printf("SET %d\n",flag++);
		gets(str[0]);
		for ( i = 0; i < num; i++)
			gets(str[i]);
		if (num % 2 == 0) {
			i=0;
			while ( i < (num-1)) {
				puts(str[i]);
				i += 2;
			}
			i--;
			while ( i > 0 ) {
				puts(str[i]);
				i -= 2;
			}
		}
		else {
			i = 0;
			while ( i < num) {
				puts(str[i]);
				i +=2;
			}
			i-=3;
			while (i > 0) {
				puts(str[i]);
				i -= 2;
			}
		}
		scanf("%d",&num);
	}
	return 0;
}