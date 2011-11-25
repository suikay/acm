#include <iostream>
using namespace std;
int in[101],inv[101];
int road[101][101];
int main()
{
	int n, sum = 0;
	int min, mink;
	int i,j,k;
	cin >>n;
	for(int i = 0; i < n; i++)
		for( int j = 0; j < n; j++)
			cin >> road[i][j];
	in[0] = 0;
	inv[0] = 1;
	for( i = 1; i < n; i++) {
		min = 999999999;
		for(j = 0; j < i; j++)
			for(k = 0; k < n; k++)
				if( !inv[k] && road[(in[j])][k] && road[(in[j])][k] < min) {
					min = road[(in[j])][k];
					mink = k;
				}
		in[j] = mink;
		inv[mink] = 1;
		sum += min;
	}
	cout << sum;
}