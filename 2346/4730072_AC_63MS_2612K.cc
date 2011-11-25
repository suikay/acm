#include<math.h>
#include<stdio.h>
int poss[6][100020];
int main()
{
	int N;
	scanf("%d",&N);
	poss[0][0] = 1;
	for(int i = 0; i < N/2; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 100000; k++)
				poss[i+1][k+j] += poss[i][k];
	long long res(0);
	for(int i = 0; i < 100000; i++)
		res += poss[N/2][i]*poss[N/2][i];
	printf("%I64d\n",res);
	return 0;
}