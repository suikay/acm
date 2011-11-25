#include <stdio.h>
#include <stdlib.h>
unsigned long a[500005];
int main()
{
	unsigned long n,count,i,j,temp;
	scanf("%d",&n);
	while( n > 0) {
			count = 0;
			max = -1;
			for( i = 0; i < n;i++) {
				scanf("%d",&a[i]);
				if( a[i] > max) 
					max = a[i];
				else
					for(j = 0;j < i; j++)
						if( a[j] > a[i])
							count++;
			}
		printf("%d\n",count);
		scanf("%d",&n);
	}
}