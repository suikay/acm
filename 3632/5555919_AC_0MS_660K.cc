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
	int t,n,x[1000];
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> x[i];
		sort(x,x+n);
		cout << (x[n-1] - x[0])*2 << endl;
	}
	return 0;
}