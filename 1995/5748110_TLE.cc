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
	memset(v,0,sizeof(v));
	a %= m;
	int ori = a;
	a = 1;
	for(int i = 1; i <= b; i++) {
		a = (a * ori) % m;
		if(v[a] > 0) {
			int dif = i - v[a];
			for(int j = (b-i)%dif; j > 0; j--)
				a = (a*ori)%m;
			return a;
		}
		v[a] = i;
	}
	return a;
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