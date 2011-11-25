#include <stdio.h>
int main()
{
	char c;
	int oc,xc,num,i,j;
	scanf("%d",&num);
	for ( i = 0 ; i < num; i ++)
	{
		xc = oc = 0;
		for ( j = 0 ; j < 9 ; j++)
		{
			do {
			scanf("%c",&c);
			} while ( c =='\n' || c == ' ');
			if (c == 'X')
				xc ++;
			else
				if (c == 'O')
					oc++;
		}
		if ( (xc == oc) || ( xc==(oc+1)))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
