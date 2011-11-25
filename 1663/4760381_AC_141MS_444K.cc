#include<iostream>
using namespace std;
int main()
{
	int n;
	int x,y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		if(x!=y && x!=(y+2))	{
			cout << "No Number" << endl;
			continue;
		}
		if(x == y)
		{
			if( x % 2)
				cout << 2 * x - 1 << endl;
			else
				cout << 2 * x << endl;
		}
		else
		{
			if( x % 2)
				cout << (x - 3) * 2 + 3 << endl;
			else
				cout << (x - 2 ) * 2 + 2 << endl;
		}
	}
	return 0;
}