#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main()
{
	int k,n,res,a,b,m,r;
	scanf("%d",&k);
	while(k--)
	{
		res = 0;
		scanf("%d%d",&m,&n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&a,&b);
			a %= m;
			r = 1;
			while(b) {
				if(b & 1) {
					r = (r*a)%m;
				}
				a = (a*a) % m;
				b >>= 1;
			}
			r %= m;
			res += r;
		}
		printf("%d\n",res%m);
	}

	return 0;
}