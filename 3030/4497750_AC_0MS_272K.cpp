#include <iostream>
using namespace std;
int main()
{
	int n;
	int r,e,a;
	cin >> n;
	for( int i = 0; i < n; i++) {
		cin >> r >> e >> a;
		e -= a;
		if(r > e)
			cout << "do not advertise\n";
		if( r == e)
			cout <<  "does not matter\n";
		if( r < e) 
			cout << "advertise\n";
	}
}