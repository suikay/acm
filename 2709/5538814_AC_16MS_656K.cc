#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int ori[12],last[12];
	int n,want,_max,pp;
	while(cin >> n && n)
	{
		_max = 0;
		for(int i = 0; i < n; i++) {
			cin >> ori[i];
			if(ori[i] > _max)
				_max = ori[i];
		}
		if(_max <= 0)
			_max = 0;
		else
			_max = ((_max - 1) / 50 + 1) * 50;
		cin >> want;
		for(int i = 0; i < n; i++)
			last[i] = _max - ori[i];
		pp = want * 3;
		for(int i = 0; i < n; i++) 
			pp -= min(want,last[i]);
		if(pp <= 0) {
			cout << _max / 50 << endl;
			continue;
		}
		int inc = (1);
		while (true)
		{
			pp = want * 3;
			for(int i = 0; i < n; i++) {
				last[i] += 50;
				pp -= min(want,last[i]);
			}
			if(pp <= 0) {
				cout << _max / 50 + inc<< endl;
				break;
			}
			inc++;
		}
	}
	return 0;
}

/*
3 40 95 21 0
7 25 60 400 250 0 60 0 500
4 90 95 75 95 10
4 90 95 75 95 11
5 0 0 0 0 0 333
0
*/