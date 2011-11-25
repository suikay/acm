#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,m,pointL,point[10005],position,j,k;
	char temp[100],*stemp;
	scanf("%d\n",&n);
	for( i = 0; i < n;i++)
		gets(temp);
	scanf("%d\n",&m);
	for( i = 0; i < m; i++) {
		position = 1;
		for( j = 0; j < n; j++) {
			gets(temp);
			sscanf(temp,"%d",&point[j]);
			stemp = strchr(temp,' ') + 1;
			if( !strcmp(stemp,"Li Ming"))
				pointL = point[j];
		}
			for( k = 0; k < n; k++)
				if( point[k] > pointL )
					position++;
		printf("%d\n",position);
	}
}