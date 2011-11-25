#include <stdio.h>
long long data[2005][2005];
#define MAX 2147483647
int main()
{
	int i,j,k,t,n,a,b,c;
	scanf("%d%d",&t,&n);
	for ( i = 1; i <= n + 1; i++)
		for ( j = 1; j <= n + 1; j++)
			data[i][j] = MAX;
	for ( i = 0; i < t ;i ++) {
		scanf("%d%d%d",&a,&b,&c);
		if ( data[a][b] > c)
			data[a][b] = c;
	}
	for ( i = 2; i < t; i++)
			for ( k =2; k <= t; k++)
				if ((data[1][i] + data[i][k]) < data[1][k]) 
					data[1][k] = data[1][i] + data[i][k];
	printf("%d",data[1][n]);
	return 0;
}