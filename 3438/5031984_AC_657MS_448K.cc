#include<sstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string x;
	char last;
	int count;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> x;
		last = x[0];
		count = 1;
		for(int i = 1; i < x.size(); i++)
			if(last == x[i])
				count++;
			else
			{
				cout << count << last;
				last = x[i];
				count = 1;
			}
		cout << count << last << endl;
	}
	return 0;
}