#include<iostream>
using namespace std;
int main()
{
	int h,m;
	char c;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> h>> c>>m;
		if(m)
			cout << "0" << endl;
		else
			cout << ((h==12)?24:((h+12)%24)) << endl;
	}
	return 0;
}