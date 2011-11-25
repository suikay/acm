#include <stdio.h>
int main()
{
	long num,temp;
	scanf("%d",&num);
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
		scanf("%d",&num);
	}
	return 0;
}
