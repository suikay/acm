#include <stdio.h>
int main()
{
	int num,i,j,temp,count = 0;
	scanf("%d",&num);
	for ( i = 1; i <= num/2 ; i++)
		for (j = i + 1; j <= num/2 + 1; j++) {
			if ( (temp = (i + j ) * ( j - i + 1) /2 )== num)
				count ++;
			else
				if (temp > num)
					j = num;
		}
	printf("%d",count+1);
	return 0;
}