#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st[110];
	string tmp,url;
	int end,now;
	now = 0;
	st[0] = "http://www.acm.org/";
	end = now = 0;
	while(cin >> tmp)
	{
		if(tmp == "VISIT")
		{
			cin >> url;
			cout << url << endl;
			st[++now] = url;
			end = now;
		}
		if(tmp == "BACK")
		{
			if(now == 0)
				cout << "Ignored" << endl;
			else
				cout << st[--now] << endl;
		}
		if(tmp == "FORWARD")
		{
			if(now == end)
				cout << "Ignored" << endl;
			else
				cout << st[++now] << endl;
		}
		if(tmp == "QUIT")
			return 0;
	}
	return 0;
}

