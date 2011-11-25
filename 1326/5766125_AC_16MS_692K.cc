#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
string a,b;
int main()
{
	string a;
	int dis,res;
	char type;
	while(true)
	{
		res = 0;
		while(true)
		{
			cin >> a;
			if(a[0] == '0')
				break;
			if(a[0] == '#')
				return 0;
			cin >> a >> dis >> type;
			switch(type){
				case 'F': res += 2*dis; break;
				case 'B': res += dis+(dis+1)/2; break;
				default: res += (dis>500)?dis:500;
			}
		}
		cout << res << endl;
	}

	return 0;
}