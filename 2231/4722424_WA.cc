#include<algorithm>
#include<stdio.h>
using namespace std;
long long cows[10001];
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		for(int i = 0; i < N; i++)
			scanf("%lld",&cows[i]);
		sort(cows,cows + N);
		long long res(0);
		long long tmp;
		for(int i = 1; i < N; i++)	{
			tmp = cows[i] - cows[i-1];
			res += tmp*i*(N-i);
		}
		printf("%lld\n",res*2);
	}
	return 0;
}