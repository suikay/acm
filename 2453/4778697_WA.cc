#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int b[22],w;
	while(cin >> w){
		for(int i = 0; i < 22; i++)
			b[21-i] = (w & (1 << i)) >> i;
		next_permutation(b,b+22);
		int j = 0;
		for(int i = 21; i >= 0; i--)
			j |= ((b[21-i] << i)& (1 << i));
		cout << j << endl;
	}
	return 0;
}