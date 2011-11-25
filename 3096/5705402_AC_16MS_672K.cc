#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string,bool>check;
int main()
{
	string ori,tmp;
	int len;
	bool res;
	while(cin >> ori)
	{
		if(ori == "*")
			return 0;
		res = true;
		len = ori.size();
		for(int i = 1;res && i < len; i++) {
			check.clear();
			for(int j = 0;res && (j + i < len); j++) {
				tmp = "";
				tmp.push_back(ori[j]);
				tmp.push_back(ori[i+j]);
				if(check.count(tmp)) 
					res = false;
				else
					check[tmp] = true;
			}
		}
		if(res) 
			cout << ori << " is surprising." << endl;
		else
			cout << ori << " is NOT surprising." << endl;
	}
	return 0;
}
