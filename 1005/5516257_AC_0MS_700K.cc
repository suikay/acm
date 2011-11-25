#include <iostream>
using namespace std;
const double PI(3.1415926),ESP(10e-5);
int main()
{
	double x,y;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		cout << "Property " <<
			i << ": This property will begin eroding in year " <<
			(int)(PI*(x*x+y*y)/100.0+ESP)+1 << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}