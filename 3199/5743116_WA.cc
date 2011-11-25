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
	long long n,d,res,r,ten(1);
	ten *= 10000000;
	ten *= 100000000;
	while(true)
	{
		cin >> n >> d;
		if(!n && !d)
			return 0;
		res = n;
		r = 0;
		for(int i = 1; i < d; i++) {
			res *= n;
			r *= n;
			r += res/ten;
			res %= ten;
		}
		if(r != 0) 
			printf("%lld%.015lld\n",r,res);
		else
			printf("%lld\n",res);
	}

	return 0;
}