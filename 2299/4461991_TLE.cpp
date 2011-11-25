#include <stdio.h>
#include <stdlib.h>
unsigned long a[500005];
int main()
{
	unsigned long n,count,i,j,k,temp;
	scanf("%d",&n);
	while( n > 0) {
		for( i = 0; i < n;i++) 
				scanf("%d",&a[i]);
			count = 0;
			for( j = 1; j < n;j++)
				for( k = n-1; k >= j;k--)
					if( a[k-1] > a[k] ) {
						count++;
						temp = a[k-1];
						a[k-1] = a[k];
						a[k] = temp;
					}
		printf("%d\n",count);
		scanf("%d",&n);
	}
}