#include <stdio.h>
#include <stdlib.h>
unsigned long a[500005];
#define swap(k) 	count++;temp = a[k-1];	a[k-1] = a[k];	a[k] = temp;
int main()
{
	unsigned long n,count,i,j,temp;
	scanf("%d",&n);
	while( n > 0) {
			count = 0;
			for( i = 0; i < n;i++) {
				scanf("%d",&a[i]);
				j = i;
				for(j = 0;j < i; j++)
					if( a[j] > a[i])
						count++;
			}
		printf("%d\n",count);
		scanf("%d",&n);
	}
}