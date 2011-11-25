#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;
long long count[40][40];
int map[40][40];
int main()
{
	int n;
	char c;
	while(scanf("%d",&n)&&n>0)
	{
		memset(count,0,sizeof(count));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				cin >> c;
				map[i][j] = c - '0';
			}
		count[n-1][n-1] = 1;
		for(int i = n-1; i >= 0; i--)
			for(int j = n-1; j >= 0; j--){
				for(int ii = i-1; ii >= 0; ii--)
					if(map[ii][j] == i - ii)
						count[ii][j] += count[i][j];
				for(int jj = j-1; jj >= 0; jj--)
					if(map[i][jj] == j - jj)
						count[i][jj] += count[i][j];
			}
		cout << count[0][0] << endl;
	}
	return 0;
}