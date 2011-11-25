#include <iostream>
using namespace std;
int main()
{
	char str[32];
	int two,i;
	long long sum;
	cin >> str;
	while( str[0] != '0')
	{
		two = 1;
		sum = 0;
		for ( i = strlen(str) - 1;  i >= 0 ; i--)
		{
			two *= 2;
			sum += ( str[i] - '0') * (two - 1);
		}
		cout << sum << endl;
		cin >> str;
	}
	return 0;
}