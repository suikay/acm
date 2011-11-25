#include<algorithm>
#include<stdio.h>
using namespace std;
long long cows[10001];
int main()
{
	long long N;
	scanf("%lld",&N);
	for(long long i = 0; i < N; i++)
		scanf("%lld",&cows[i]);
	sort(cows,cows + N);
	long long j = 1;
	unsigned long long res(0);
	for(long long i = 0; i < N-1; i++,j++)
		res += (cows[i+1] - cows[i])*2*j*(N-j);
	printf("%llu\n",res);
	return 0;
}