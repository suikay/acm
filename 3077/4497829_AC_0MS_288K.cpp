#include <iostream>
using namespace std;
int main()
{
	int n;
	unsigned long long num,ten;
	cin >> n;
	for( int i = 0; i < n; i++) {
		ten = 10;
		cin >> num;
		while( ten < num ) {
			if((num % ten)/ (ten / 10)> 4 )
				num = (num / ten + 1) * ten;
			else
				num = num / ten * ten;
			ten *= 10;
		}
		cout << num << endl;
	}
}