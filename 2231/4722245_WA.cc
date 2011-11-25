#include<algorithm>
#include<stdio.h>
using namespace std;
int cows[10001];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		scanf("%d",&cows[i]);
	sort(cows,cows + N);
	int j = 1;
	int res(0);
	for(int i = 0; i < N-1; i++,j++)
		res += (cows[i+1] - cows[i])*2*j*(N-j);
	printf("%d\n",res);
	return 0;
}