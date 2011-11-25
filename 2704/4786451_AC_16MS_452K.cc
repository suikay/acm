#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;
long long icount[40][40];
int map[40][40];
int main()
{
	int n;
	char c;
	while(scanf("%d",&n)&&n>0)
	{
		memset(icount,0,sizeof(icount));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				cin >> c;
				map[i][j] = c - '0';
			}
		icount[n-1][n-1] = 1;
		for(int i = n-1; i >= 0; i--)
			for(int j = n-1; j >= 0; j--){
				for(int ii = i-1; ii >= 0; ii--)
					if(map[ii][j] == i - ii)
						icount[ii][j] += icount[i][j];
				for(int jj = j-1; jj >= 0; jj--)
					if(map[i][jj] == j - jj)
						icount[i][jj] += icount[i][j];
			}
		cout << icount[0][0] << endl;
	}
	return 0;
}