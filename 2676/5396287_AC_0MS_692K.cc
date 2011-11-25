/*
ID: immozer1
PROG: ****
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define _CUBE(x,y) ((x)/3*3+(y)/3)
using namespace std;
bool rv[10][10],rc[10][10],rm[10][10],found;
int m[10][10];
bool dfs(int x,int y) {
	if(x == -1 )
		return true;
	if(m[x][y] != 0) {
		if(y == 0)
			return dfs(x-1,8);
		else
			return dfs(x,y-1);
	}
	else {
		int cube = _CUBE(x,y);
		for(int i = 1; i <= 9; i++) 
			if(!rc[x][i] && !rv[y][i] && !rm[cube][i]) {
					rc[x][i] = rv[y][i] = rm[cube][i] = true;
					m[x][y] = i;
					if(y == 0){
						if(dfs(x-1,8))
							return true;
					}
					else
						if(dfs(x,y-1))
							return true;
					m[x][y] = 0;
					rc[x][i] = rv[y][i] = rm[cube][i] = false;
			}
	}
	return false;
}

void init()
{
	int cube;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++) 
		if(m[i][j] != 0){
			cube = _CUBE(i,j);
			rc[i][m[i][j]] = rv[j][m[i][j]] = rm[cube][m[i][j]] = true;
		}
}
int main()
{
	int n;
	cin >> n;
	char tmp;
	while(n--)
	{
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++) {
				cin >> tmp;
				m[i][j] = tmp-'0';
			}
		found = false;
		memset(rc,false,sizeof(rc));
		memset(rv,false,sizeof(rv));
		memset(rm,false,sizeof(rm));
		init();
		dfs(8,8);
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				cout << m[i][j] ;
			cout << endl;
		}
	}
	return 0;
}