#include <stdio.h>
#define add(x) a[x/1600]++;b[x/80]++;c[x/4]++;d[x]++;
int a[21];
int b[401];
int c[8001];
int d[32001];
int count[32000];
int main()
{
	int n, sum;
	int x, y, j;
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		sum = 0;
		scanf("%d%d",&x,&y);
		for( j = 0; j < (x/1600); j++)
			sum += a[j];
		for( j = (x/1600)*20 ; j < (x/80); j++)
			sum += b[j];
		for( j = (x/80)*20; j < (x/4); j++)
			sum += c[j];
		for( j = (x/4)*4; j<= x; j++)
			sum += d[j];
		count[sum]++;
		add(x);
	}
	for( int i = 0; i < n; i++)
		printf("%d\n",count[i]);
}

