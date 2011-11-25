#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
char arr[300][10] = {".-","-...","-.-.","-..",".","..-.","--.",
					"....","..",".---","-.-",".-..","--","-.",
					"---",".--.","--.-",".-.","...","-",
					"..-","...-",".--","-..-","-.--","--.."};
map<char,string> zz;
map<string,char> z;
int main()
{
	string tmp,ll;
	int pos, t;
	vector<int> num;
	for(int i = 0; i < 26; i++)
		zz['A'+i] = arr[i];
	zz['_'] = "..--"; zz[','] = ".-.-"; zz['.'] = "---."; zz['?'] = "----";
	for(map<char,string>::iterator itr = zz.begin(); itr != zz.end(); itr++)
		z[itr->second] = itr->first;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++)
	{
		printf("%d: ",i);
		cin >> tmp;
		pos = 0;
		ll = "";
		num.clear();
		for(int j = 0; j < tmp.size(); j++) {
			num.push_back(zz[tmp[j]].size());
			ll += zz[tmp[j]];
		}
		reverse(num.begin(),num.end());
		for(int j = 0; j < num.size(); j++)
		{
			cout << z[ll.substr(pos,num[j])];
			pos += num[j];
		}
		cout << endl;
	}

	return 0;
}