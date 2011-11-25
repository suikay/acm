#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 110;
bool v[N*N][N];
int cnt[N][10];
void f(int m,int n)
{
//	cout << m << " "<< n << endl;
	if(m == 0 || v[m][n])
		return;
	v[m][n] = true;
	cnt[n][m/n]++;
	f(m%n*10,n);
}
int main()
{
	for(int i = 2; i < 100; i++)
		f(10,i);
	cnt[100][1] = 1;
	int n,k,res;
	while( cin >> n >> k) {
		res = 0;
		for(int i = 2; i <= n; i++)
			res += cnt[i][k];
		cout << res << endl;
	}

	return 0;
}