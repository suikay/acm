#include <stdio.h>
#include <memory.h>
#include <math.h>
//#define 2147483648
int test(int a,int b, int c)
{
	int i;
	if(c%a)
		return false;
	for(i = 0;c&&!(c%a) && i < b;i++)
		c /= a;
	if(i!=b)
		return false;
	return true;
}
int main()
{
	int up,down;
	double di;
	int n;
	while(scanf("%d",&n)&&n) {
		di = log(1.0*n);
		bool flag = false;
		for(int p = (di/0.3);!flag && p > 0;p--) {
			up = exp(1.0*di/p)+1;
			down = up - 1;
			while(!flag && up>= down && up > 1) {
				if(test(up,p,n)) {
					printf("%d\n",p);
					flag = true;
				}
				up --;
			}
		}
	}
	return 0;
}