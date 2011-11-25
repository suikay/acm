#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int m,v[50000];
int f(int a,int b)
{
	int res(1);
	a %= m;
	while(b) {
		if(b & 1) {
			res = (res*a)%m;
		}
		a = (a*a) % m;
		b >>= 1;
	}
	return res%m;
}

int main()
{
	int k,n,res,a,b;
	scanf("%d",&k);
	while(k--)
	{
		res = 0;
		scanf("%d%d",&m,&n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&a,&b);
			res += f(a,b);
		}
		printf("%d\n",res%m);
	}

	return 0;
}