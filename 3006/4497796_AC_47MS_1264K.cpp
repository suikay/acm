#include <string>
#include <iostream>
using namespace std;
bool nPrime[1000000];
int main()
{
	int j;
	nPrime[0] = nPrime[1] = true;
	for( int i = 2; i < 100000; i++)
		if(!nPrime[i]) {
			j = i + i;
			while( j < 1000000) {
				nPrime[j] = true;
				j += i;
			}
		}
	int m,n,o;
	int res;
	while( true ) {
		cin >> m >> n >> o;
		if(!m)
			break;
		res = m;
		while(o) {
			if(!nPrime[res])
				o--;
			res += n;
		}
		cout << res - n << endl;
	}
}