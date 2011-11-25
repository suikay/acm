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
	int n,k,last;
	int s,t,r,once,res;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
	{
		res = 0;
		last = n;
		cin >> s >> t >> r;
		once = s*t;
		while(last > once)
		{
			res += t + r;
			last -= once;
		}
		res += last/s;
		if(last % s)
			res++;
		cout << res << endl;
	}
	return 0;
}