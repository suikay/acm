#include <stdio.h>
long long data[1005][1005];
#define MAX 214748364
int main()
{
	int i,j,k,t,n,a,b,c;
	scanf("%d%d",&t,&n);
	for ( i = 1; i <= n ; i++)
		for ( j = 1; j <= n ; j++)
			data[i][j] = MAX;
	for ( i = 0; i < t ;i ++) {
		scanf("%d%d%d",&a,&b,&c);
		if ( data[a][b] > c) {
			data[a][b] = c;
			data[b][a] = c;
		}
	}
	for ( i = 2; i < n; i++)
			for ( k =2; k <= n; k++)
				if ((data[1][i] + data[i][k]) < data[1][k]) 
					data[1][k] = data[1][i] + data[i][k];

	printf("%d",data[1][n]);
	return 0;
}