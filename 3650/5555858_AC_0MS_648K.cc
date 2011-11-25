#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<char,string> p;
void mm()
{
	p[' '] = "%20";
	p['!'] = "%21";
	p['$'] = "%24";
	p['%'] = "%25";
	p['('] = "%28";
	p[')'] = "%29";
	p['*'] = "%2a";
}
int main()
{
	string res;
	char tmp[1000];
	mm();
	while(gets(tmp)) 
	{
		if(tmp[0] == '#')
			return 0;
		for(int i = 0; i < strlen(tmp); i++)
			if(p.count(tmp[i]) == 0)
				res.push_back(tmp[i]);
			else
				res += p[tmp[i]];
		cout << res << endl;
		res = "";
	}

	return 0;
}