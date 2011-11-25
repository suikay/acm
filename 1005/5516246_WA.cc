#include <iostream>
using namespace std;
const double PI(3.1415926),ESP(10e-5);
int main()
{
	double R,r;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> R >> r;
		cout << "Property " <<
			i << ": This property will begin eroding in year " <<
			(int)(PI*(R*R-r*r)/100.0)+1 << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}