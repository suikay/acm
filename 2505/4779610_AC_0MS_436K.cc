#include<iostream>
using namespace std;
int main()
{
	bool win = true;
	long long n,big;
	while(cin >> n)
	{
		win = true;
		big = 9;
		while(n > big){
			if(win)
				big *= 2;
			else
				big *= 9;
			win = !win;
		}
		if(win)
			cout << "Stan wins." << endl;
		else
			cout << "Ollie wins." << endl;
	}
	return 0;
}