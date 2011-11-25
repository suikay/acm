#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
char mapping[256];
struct Number
{
	char n[9];
	friend bool operator<(const Number &a,const Number &b)//定义struct比较方法
	{
		return strcmp(a.n,b.n)<0;
	}
};
map<Number,int> phone_book;
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
	int n,pt;
	char num[100];
	Number tmp;
	init();
	cin >> n;
	gets(num);
	while(n--)
	{
		gets(num);
		pt = 0;

		for(int i = 0; num[i] != '\0'; i++)
		if(num[i] != '-') {
			if(pt == 3) 
				tmp.n[pt++] = '-';
			tmp.n[pt++] = mapping[num[i]];
		}
		tmp.n[8] = '\0';

		phone_book[tmp]++;
	}
	map<Number,int>::iterator itr;
	for(itr = phone_book.begin(); itr != phone_book.end(); itr++)
		if(itr->second > 1)
			printf("%s %d\n",itr->first.n,itr->second);
	return 0;
}