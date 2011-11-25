#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
long long cows[10001];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		scanf("%I64d",&cows[i]);
	sort(cows,cows + N);
	unsigned long long res(0),tmp;
	for(int i = 1; i < N; i++)	{
		tmp = cows[i] - cows[i-1];
		res += tmp*i*(N-i);
	}
	res *= 2;
	printf("%I64d\n",res);
	return 0;
}