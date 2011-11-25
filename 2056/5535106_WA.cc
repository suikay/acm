#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 210;
char board[N][N];
int rec[N];
int main()
{
	int m,n,b_cnt,sum,ok,i,j,ori;
	while(true)
	{
		sum = 0;
		b_cnt = 0;
		cin >> n >> m;
		if(m == 0 && n == 0)
			return 0;
		cout << "A" << endl;
		for(i = 0; i <= n+1; i++)
			for(j = 0; j <= m+1; j++)
				board[i][j] = 'S';
		for(i = 1; i <= n; i++)
			cin >> board[i]+1;
		for(i = 1; i <= n; i++) 
			for(j = m; j >= 1; j--)
				if(board[i][j] == 'S') {
					rec[i] = j;
					b_cnt++;
				}
		for(i = 1; i <= n; i++) {
//			cout << "i    " << i <<  endl;
			ori = rec[i] + 1;
			if(i == 1 && ori == m)
				continue;
			if(board[i][ori] != 'B' || board[i-1][ori] != 'S')
				continue;
			for(j = i; j <= n; j++) 
				if(board[j+1][ori] == 'S') {
					ok = j;
					break;
				} else if(board[j][ori-1] == 'B') {
					ok = -j;
					break;
				}
//			cout << "OK   " << ok << endl;
			if(ok == n && ori == m)
				break;
			if(ok > 0) {
				if(i == 1)
					sum--;
				if(ok == n)
					sum--;
				sum += 2;
				i = ok;
			}
			else {
				i = -ok;
				i--;
			}
		}
		cout << b_cnt - sum << endl;
	}
	return 0;
}
