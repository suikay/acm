#include <stdio.h>
int data[2002][2002];
int main()
{
	int i,j,k,t,n,a,b,c;
	scanf("%d%d",&t,&n);
	for ( i = 0; i < n;i ++) {
		scanf("%d%d%d",&a,&b,&c);
		data[a][b] = c;
	}
	for ( i = 2; i < t; i++)
			for ( k =2; k <= t; k++)
				if ( data[1][i] && data[i][k]&&(((data[1][i] + data[i][k]) < data[1][k]) || !data[1][k]))
					data[1][k] = data[1][i] + data[i][k];
	printf("%d",data[1][t]);
	return 0;
}