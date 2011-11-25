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
	string a,b;
	bool v[1000];
	int n,ra,rb;
	cin >> n;
	while(n--)
	{
		memset(v,false,sizeof(v));
		ra = rb = 0;
		cin >> a >> b;
		for(int i = 0; i < a.size(); i++)
			v[a[i]] = true;
		for(int i = 0; i < b.size(); i++)
			if(a[i] == b[i])
				ra++;
			else if(v[b[i]])
				rb++;
		cout << ra << "A" << rb <<"B"<< endl;
	}

	return 0;
}