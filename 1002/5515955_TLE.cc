#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string,int> phone_book;
char mapping[256];
void init()
{
	for(int i = '0'; i <= '9'; i++)
		mapping[i] = i;
	for(int i = 'A'; i <= 'P'; i++)
		mapping[i] = '2' + (i-'A')/3;
	for(int i = 'R'; i <= 'Y'; i++)
		mapping[i] = '2' + (i-'A'-1)/3;
}
string clean(const string &ori)
{
	string tmp;
	for(int i = 0; i < ori.size(); i++)
		if(ori[i] != '-')
			tmp += mapping[ori[i]];
	tmp.insert(3,"-");
	return tmp;
}
int main()
{
	int n;
	string num;
	init();
	cin >> n;
	while(n--)
	{
		cin >> num;
		phone_book[clean(num)]++;
	}
	map<string,int>::iterator itr;
	for(itr = phone_book.begin(); itr != phone_book.end(); itr++)
		if(itr->second > 1)
			cout << itr->first << " " << itr->second << endl;
	return 0;
}