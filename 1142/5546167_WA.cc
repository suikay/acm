#include <stdio.h>
#include <string.h>
const int N = 10000;
bool bp[N];
int prime[N],pn;
void mp()
{
	pn = 0;
	memset(bp,true,sizeof(bp));
	bp[0] = bp[1] = false;
	for(int i = 2; i < N; i++)
		if(bp[i]) {
			prime[pn++] = i;
			for(int j = i*i; j < N; j+=i)
				bp[j] = false;
		}
}
int sum(int x)
{
	int ans(0);
	while(x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int cnt(int x) 
{
	int sum1,tmp,i,j;
	for(i = x;true; i++)
	{
		tmp = i;
		sum1 = 0;
		for(j = 0;tmp > 1 && j < pn; j++)
			while(!(tmp % prime[j])) {
				sum1 += sum(prime[j]);
				tmp /= prime[j];
			}
		if(tmp != 1)
			sum1 += sum(tmp);
//		printf("%d\n",tmp);
//		printf("SUM  %d\n",sum1);
		if(sum(i) == sum1)
			return i;
	}
	return 0;
}
int main()
{
	int n;
	mp();
//	printf("pn %d\n",pn);
	while(scanf("%d",&n) && n)
		printf("%d\n",cnt(n));
	return 0;
}
//4937774