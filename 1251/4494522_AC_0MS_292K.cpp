#include <iostream>
using namespace std;
int in[26];
int road[26][26];
int inv[26];
int main()
{
	int n, v, weigh;
	int min,mink,j;
	char x, y;
	cin >> n;
	while(n) {
		int sum = 0;
		for( int i = 0; i < 26; i++)
			for( int j = 0; j < 26; j++)
				road[i][j] = 0;
		memset(inv,0,26 * sizeof(int));
		for( int i = 0; i < n - 1; i++) {
			cin >> x >> v;
			x -= 'A';
			for( int j = 0; j < v; j++) {
				cin >> y >> weigh;
				y -= 'A';
				road[x][y] = road[y][x] = weigh;
			}
		}
		in[0] = 0;
		inv[0] = 1;
		for( int i = 1; i < n; i++) {
			min = 99999999;
			for(j = 0; j < i; j++)
				for( int k = 0; k < n; k++)
					if(!inv[k] && road[(in[j])][k] && road[(in[j])][k] < min) {
						min = road[in[j]][k];
						mink = k;
					}
			in[j] = mink;
			inv[mink] = 1;
			sum += min;
		}
		cout << sum << endl;
		cin >> n;
	}
}