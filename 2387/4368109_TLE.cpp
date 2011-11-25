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
	for ( i = 1; i <= t; i++)
		for (j = 1; j <= t; j++)
			for ( k = j +1; k <= t; k++)
				if ((((data[j][i] + data[i][k]) < data[j][k]) || !data[j][k])&&( data[j][i] && data[i][k]))
					data[j][k] = data[j][i] + data[i][k];
	printf("%d",data[1][t]);
	return 0;
}