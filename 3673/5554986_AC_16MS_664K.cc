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
	vector<int>aa,bb;
	long long a,b;
	cin >> a >> b;
	while(a) {
		aa.push_back(a % 10);
		a /= 10;
	}
	while(b) {
		bb.push_back(b % 10);
		b /= 10;
	}
	long long x(0);
	for(int i = 0; i < aa.size(); i++)
		for(int j = 0; j < bb.size(); j++)
			x += aa[i] * bb[j];
	cout << x << endl;

	return 0;
}