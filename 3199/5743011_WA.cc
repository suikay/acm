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
	long long n,d,res;
	while(true)
	{
		cin >> n >> d;
		if(!n && !d)
			return 0;
		res = n;
		for(int i = 1; i < d; i++)
			res *= n;
		cout << res << endl;
	}

	return 0;
}