#include <stdio.h>
int main()
{
	int a,b;
	while(true) {
		scanf("%d",&a);
		if( a <= 0)
			break;
		while( a > 9) {
			b = 0;
			while(a) {
				b += a % 10;
				a = a/10;
			}
			a = b;
		}
		printf("%d\n",a);
	}
}