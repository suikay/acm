#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 1300;
int col,row,match[N];
bool v[N],map[N][N];

bool dfs(int x)
{
	for(int i = 0; i < row; i++) {
		if(!v[i] && map[x][i])
		{
			v[i] = true;
			if(match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 0; i < col; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

void input()
{
	static char dummy[100],farm[55][55];
	int m,n;
	scanf("%d%d",&m,&n);gets(dummy);
	for(int i = 0; i < m; i++)
		gets(farm[i]);
	col = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(farm[i][j] == '*') {
				for(int k = j;farm[i][k] == '*' && k < n; k++)
					farm[i][k] = col;
				col++;
			}
	row = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(farm[j][i] != '.') {
				for(int k = j; farm[k][i] != '.' && k < m; k++) {
					map[farm[k][i]][row] = 1;
					farm[k][i] = '.';
				}
				row++;
			}
}

int main()
{
	input();
	printf("%d\n",MaxMatch());

	return 0;
}