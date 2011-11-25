#include<stdio.h>
#define M 100010
int primes[M];
bool bp[M*14];
void mp()
{
	int count(0);
	for(int i = 2; count < M; i++)
		if(!bp[i]){
			primes[count++] = i;
		for(int j = 2*i; j < M*14; j+=i)
			bp[j] = true;
		}
}
int find(int x)
{
	int left = 0,right = M;
	int mid = (left + right) >> 1;
	while(((long long)(x-primes[mid-1])*(x-primes[mid])) > 0){
		if(x > primes[mid])
			left = mid;
		else
			right = mid;
		mid = (left + right) >> 1;
	}
	return mid;
}
int main()
{
	mp();
	int n,tmp;
	while(scanf("%d",&n))
	{
		if(!n)
			return 0;
		tmp = find(n);
		if(primes[tmp] != n && primes[tmp-1] != n)
			if(primes[tmp] > n)
				printf("%d\n",primes[tmp] - primes[tmp-1]);
			else
				printf("%d\n",primes[tmp+1] - primes[tmp]);
		else
			printf("0\n");
	}
	return 0;
}
