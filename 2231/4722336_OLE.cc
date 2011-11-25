#include<algorithm>
#include<stdio.h>
using namespace std;
long long cows[10001];
int main()
{
	long long N;
	while(scanf("%lld",&N)	)
	{
		for(long long i = 0; i < N; i++)
			scanf("%lld",&cows[i]);
		sort(cows,cows + N);
		long long res(0);
		for(long long i = 1; i < N; i++)
			res += (cows[i] - cows[i-1])*2*i*(N-i);
		printf("%lld\n",res);
	}
	return 0;
}