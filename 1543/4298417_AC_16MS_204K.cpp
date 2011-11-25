#include <stdio.h>
int main()
{
	int i,j,k,num;
	long data[101];
	for ( i = 0; i < 101 ;i ++)
		data[i] = i * i * i;
	scanf("%d",&num);
	for (int N = 6;  N <= num ; N++)
		for ( i = 2; i < N; i++)
			for ( j = i; j < N; j++)
				for ( k = j; k < N; k++)
					if (data[N] == ( data[i] + data[j] + data[k] ))
						printf( "Cube = %d, Triple = (%d,%d,%d)\n",N, i , j , k);
	return 0;
}