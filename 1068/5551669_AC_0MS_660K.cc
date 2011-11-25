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
	string pa;
	int n,left,ca,last,a;
	bool v[50];
	cin >> ca;
	while(ca--)
	{
		cin >> n;
		memset(v,false,sizeof(v));
		last = left = 0;
		pa = " ";
		for(int i = 1; i <= n; i++) {
			cin >> a;
			for(int j = a-last; j > 0; j--)
				pa += "(";
			pa += ")";
//			cout << pa << endl;
			int now = i + a;
			while(v[now] || pa[now] == ')')
				now--;
			v[now] = true;
			cout << (i+a-now+1)/2;
			if(i != n)
				cout << " ";
			else
				cout << endl;
			last = a;
		}
	}
	return 0;
}