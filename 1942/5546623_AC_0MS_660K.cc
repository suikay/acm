#include <iostream>
using namespace std;
long long C(long long m,long long n)
{
	long double x;
	x = 1.0;
	n = max(n,(m-n));
	for(long long i = n + 1; i <= m; i++)
		x *= 1.0*i/(i-n);
	return (x+10e-2);
}
int main()
{
	long long x,y;
	while(cin >> x >> y )
	{
		if(x == 0 && y == 0)
			return 0;
		cout << C(x+y,y) << endl;
	}
	return 0;
}