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
stringstream ss(stringstream::in|stringstream::out);
string buffer;
void print()
{
	if(buffer.size() > 1) {
		buffer.resize(buffer.size()-1);
		cout << buffer << endl;
		buffer = "";
	}
}
void add(const string& word)
{
	static string check;
	check = buffer + word;
	if(check.size() > 80)
		print();
	buffer = buffer + word + " ";
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	string input,hr(80,'-');
	while(cin >> input)
	{
		if(input == "<br>") {
			if(buffer.size() == 0)
				cout << endl;
			else 
				print();
		}
		else if(input == "<hr>") {
//			if(buffer.size() != 0)
//				print();
			cout << hr << endl;
		}
		else 
			add(input);
	}
	print();

	return 0;
}