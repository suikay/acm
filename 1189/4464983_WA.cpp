#include <stdio.h>
#include <iostream>
using namespace std;
long long data[60][60];
int sq[60][60];
void f(long long &m,long long &n)
{
	n = __int64(1) << n;
	while( m % 2 == 0 && m > 1) {
		m /= 2;
		n /= 2;
	}
}
int main()
{
	int n,m;
	char c;
	scanf("%d%d",&n,&m);
	// 记录图的状态
	for( int i = 0 ; i < n;i++) {
		for ( int j = 0; j <= i; j++) {
			do{
				scanf("%c",&c);
			}while( c == ' ' || c == '\n' );
			sq[i][j] = (c == '*')?1:0;
		}
	}
	if(n == 1) {
		printf("1\n");
		return 0;
	}
	if(sq[0][0]) 
		data[0][0] = 1;
	else
		data[2][1] = 4;
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
	__int64 temp =  n;
	f(data[n][m],temp);
	cout << data[n][m] << '/' << temp << endl;
}