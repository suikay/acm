#include<iostream>
using namespace std;
int dp[150010][2];
int main()
{
	int p,tmp;
	cin >> p;
	int pos(0),neg(0);
	for(int i = 1; i <= p; i++)	{
		cin >> tmp;
		int _neg = neg;
		if(pos + tmp > neg)
			_neg = pos + tmp;
		if(neg - tmp > pos)
			pos = neg - tmp;
		neg = _neg;
	}
	cout << neg;
	return 0;
}
		