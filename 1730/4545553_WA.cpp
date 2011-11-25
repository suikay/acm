#include <stdio.h>
#include <memory.h>
#include <math.h>
//#define 2147483648
int test(int a,int b, int c)
{
	int i;
	int res=1;
	for(i = 0; i < b;i++)
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
		di = log(1.0*n*positive);
		bool flag = false;
		for(int p = (di/0.3);!flag && p > 0;p--) {
			up = positive*(exp(1.0*di/p)+2);
			down = positive*(up - 2);
			while(!flag && up != down && up != positive) {
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