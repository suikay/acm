#include <stdio.h>
int main()
{
	int i,j,k,num,two,temp;
	char c;
	scanf("%d",&num);
	for ( i = 0; i < num; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			temp = 0;
			two = 128;
			for ( k = 0; k < 8; k++) {
				do {
				c = getchar();
				} while (c != '0' && c != '1');
				temp += two * ( c - '0');
				two /= 2;
			}
			printf("%d%s",temp,(j < 3 )?".":"");
		}
		printf("\n");
	}
	return 0;
}
			