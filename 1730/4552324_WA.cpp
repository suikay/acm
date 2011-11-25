#include <stdio.h>
#include <memory.h>
#include <math.h>
int test(int a,int b, int c)
{
	long long res=1;
	for(int i = 0; i < b;i++)
		res *= a;
	return res == c;
}
int main()
{
	int up,down;
	double di;
	int n,positive;
	while(scanf("%d",&n)&&n) {
		positive = n>0?1:-1;
		if((n+1)==0||(n-1)==0)
			printf("1\n");
		di = log(1.0*n*positive);
		bool flag = false;
		for(int p = (di/0.3);!flag && p > 0;p--) {
			up = positive*(exp(1.0*di/p)+1);
			down = positive*(up - 1);
			while(!flag && up*positive >= down*positive && up != positive) {
				if(test(up,p,n)) {
					printf("%d\n",p);
					flag = true;
				}
				up-=positive;
			}
		}
	}
	return 0;
}