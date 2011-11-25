#include <stdio.h>
int color[101][101];
int main()
{
	int i,j,k;
	int t,x,y,l,count;
	char commands[100];
	char s[20];
	scanf("%d\n",&t);
	for( i = 0; i < t ;i ++) {
		gets(commands);
		sscanf(commands,"%s%d%d%d",s,&x,&y,&l);
		if(commands[0] == 'B')
			for( j = x; j < (x + l) ; j++)
				for( k = y; k < (y + l); k++)
					color[j][k] = 1;
		if(commands[0] == 'W')
			for( j = x; j < (x + l) ; j++)
				for( k = y; k < (y + l); k++)
					color[j][k] = 0;
		if(commands[0] == 'T') {
			count = 0;
			for( j = x; j < (x + l) ; j++)
				for( k = y; k < (y + l); k++)
					if( color[j][k] )
						count++;
			printf("%d\n",count);
		}
	}
	return 0;
}