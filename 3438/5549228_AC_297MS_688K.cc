#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
string f(string &x)
{
	string tmp;
	stringstream ss(stringstream::in|stringstream::out);
	int cnt,i,len;
	i = 0;
	len = x.size();
	x.push_back('\0');
	while(i < len) {
		cnt = 1;
		while(i < len && x[i] == x[i+1]) {
			cnt++;	
			i++;
		}
		ss << cnt << x[i];
		i++;
	}
//	if(len < 2 || x[len-1] != x[len-2])
//		ss << 1 << x[len-1];
	ss >> tmp;
	return tmp;
}
int main()
{
	string tmp;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> tmp;
		cout << f(tmp) << endl;
	}

	return 0;
}