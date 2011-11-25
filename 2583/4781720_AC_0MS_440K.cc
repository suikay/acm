#include<iostream>
using namespace std;
int main()
{
	int i,j,k;
	int a,b,c;
	while(cin>>i>>j>>k)
	{
		a = (k+i-2*j)/2;
		b = (4*j-3*i-k)/2;
		c = i;
		cout << 9*a+3*b+c << " ";
		cout << 16*a+4*b+c << " ";
		cout << 25*a+5*b+c << endl;
	}
	return 0;
}