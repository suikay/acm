#include <stdio.h>
#include <string.h>
int point[10005];
char names[50][35];
int main()
{
	int n,i,m,pointL,position,j,k,posiMing,itemp;
	char temp[100],*stemp;
	scanf("%d\n",&n);
	for( i = 0; i < n;i++) {
		gets(names[i]);
		if(!strcmp(names[i],"Li Ming"))
			posiMing = i;
	}
	scanf("%d\n",&m);
	for( i = 0; i < m; i++) {
		position = 1;
		for( j = 0; j < n; j++) {
			gets(temp);
			sscanf(temp,"%d",&itemp);
			stemp = strchr(temp,' ') + 1;
			for( k = 0; k < n; k++) 
				if(!strcmp(stemp,names[k]))
					break;
			point[k] += itemp;
		}
		pointL = point[posiMing];
		for( k = 0; k < n; k++)
			if( point[k] > pointL )
				position++;
		printf("%d\n",position);
	}
}