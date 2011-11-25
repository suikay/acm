#include <stdio.h>
bool npri[1000000];
int main()
{
	int i,num,temp;
	for( i = 2; i <= 1000; i ++)
		if ( !npri[i] ) {
			temp = 2 * i;
			while( temp <= 1000000)
			{
				npri[temp] = true;
				temp += i;
			}
		}
	scanf("%d",&num);
	while (num > 0)
	{
		for ( i = 3; i < num / 2 ; i++)
			if(!(npri[i] || npri[num - i]))
			{
				printf("%d = %d + %d\n",num,i,num - i);
				break;
			}
		if ( i == num/2)
			printf("Goldbach's conjecture is wrong.\n" );
		scanf("%d",&num);
	}
	return 0;
}