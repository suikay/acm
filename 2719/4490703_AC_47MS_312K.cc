#include <stdio.h>
int main()
{
	int n, last;
	scanf("%d",&n);
	while(n) {
		int r = n;
		int sum = 0;
		int nine = 1;
		while( n ) {
			last = n % 10;
			n = n / 10;
			if( last > 4)
				last --;
			sum += last * nine;
			nine *= 9;
		}
		printf("%d: %d\n",r,sum);
		scanf("%d",&n);
	}
}