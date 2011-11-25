#include <stdio.h>
bool data[10100];
int main()
{
	int i,j,k,l,temp;
	for(i = 0 ; i < 10; i++)
		for ( j = 0; j < 10; j ++)
			for ( k = 0 ; k < 10; k++)
				for (l = 0; l < 10 ; l++)
				{
					temp = i*1000+j*100+k*10+l+i+j+k+l;
					data[temp] = true;
				}
	for (i = 0; i < 10000; i++)
		if (!data[i])
			printf("%d\n",i);
	return 0;
}