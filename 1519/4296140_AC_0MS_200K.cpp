#include <stdio.h>
int main()
{
	long num,temp;
	char c = '\0';
	num = 0;
	c = getchar();
	while (c != '\n') {
		num += c - '0';
		c = getchar();
	}
	while ( num >0 ) {
		while (num > 9) {
			temp = 0;
			while ( num >0 )
			{
				temp+=( num % 10);
				num /= 10;
			}
		num = temp;
		}
		printf("%d\n",num);
		num = 0;
		c = getchar();
		while (c != '\n') {
			num += c - '0';
			c = getchar();
		}
	}
	return 0;
}
