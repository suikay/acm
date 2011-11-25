#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int cnt[1010];
void f(int x)
{
	int pp;
	for(int i = 2; i < 1000; i++) {
		if(x % i == 0) {
			pp = 0;
			while(x % i == 0) {
				pp++;
				x /= i;
			}
			if(cnt[i] < pp)
				cnt[i] = pp;
		}
	}
}

int main()
{
	int tmp,r2,k,n;
	double r1;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i < n; i++) {
			scanf("%d",&tmp);
			f(tmp);
		}
		r1 = r2 = 1;
		for(int i = 2;r2 > 0 && i < 1000; i++)
			while(cnt[i]) {
				r1 *= i;
				if(r1 > 10e9) {
					r2 = -1;
					break;
				}
				r2 *= i;
				cnt[i]--;
			}
		if(r2 < 0)
			puts("More than a billion.");
		else
			printf("%d\n",r2);
	}


	return 0;
}