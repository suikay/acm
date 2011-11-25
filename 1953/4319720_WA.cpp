#include <stdio.h>

int main()
{
	unsigned int one[47],zero[47],max,i,j,want,num;
	scanf("%d",&num);
	max = 1;
	one[1] = 1;
	zero[1] = 1;
	for( i = 0; i < num; i++)
	{
		scanf("%d",&want);
		if ( want > max) {
			for ( j = max + 1 ; j <= want; j ++)
			{
				one[j] = zero[j -1];
				zero[j] = zero[j - 1] + one[j - 1];
			}
			max = want;
			printf("%u\n",one[want] + zero[want]);
		}
		else
			printf("%u\n",one[want] + zero[want]);
	}
	return 0;
}
