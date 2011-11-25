#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	string key("QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
	string tmp;
	string::size_type i,j;
	while(getline(cin,tmp))
	{
		for(i = 0; i < tmp.size(); i++){
			j = -1;
			j = key.find(tmp[i]);
			if(j != -1)
				cout<< key[j-1];
			else
				cout << tmp[i];
		}
		cout << endl;
	}
	return 0;
}
