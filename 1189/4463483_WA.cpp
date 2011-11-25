#include <stdio.h>
#include <iostream>
using namespace std;
long long data[55][55];
int sq[55][55];
void f(long long &m,long long &n)
{
	if( m == 0) {
		n = 1;
		return ;
	}
	n = 1 << n;
	while( m % 2 == 0) {
		m /= 2;
		n /= 2;
	}
}
int main()
{
	int n,m;
	char c;
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n;i++) {
		for ( int j = 0; j <= i; j++) {
			do{
				scanf("%c",&c);
			}while( c == ' ' || c == '\n' );
			sq[i][j] = (c == '*')?1:0;
		}
	}
	data[0][0] = 1;
	for ( int i = 0; i <= n;i++)
		sq[n][i] = 1;
	for( int i = 0; i < n;i++)
		for( int j = 0;j <= i; j++) {
				if ( sq[i+1][j])
					data[i + 1][j] += data[i][j];
				else
					data[i + 3][j + 1] += 4 * data[i][j];
				if(sq[i + 1][j + 1])
					data[i + 1][j + 1] += data[i][j];
				else
					data[i + 3][j + 2] += 4 * data[i][j];
		}
	long long temp = n;
	f(data[n][m],temp);
	/*
	for( int i = 1; i <= n;i++)
		if( data[n + 1][i] ) {
			data[n][i - 1] += data[n + 1][i]/4;
			data[n][i] += data[n + 1][i] / 4;
		}
		*/
	cout << data[n][m] << '/' << temp;
}
