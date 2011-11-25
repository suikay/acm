#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 1500;
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

bool input()
{
	static char dummy[100],farm[100][100];
	int m,n,f[100][100];
	memset(map,false,sizeof(map));
	if(scanf("%d%d",&m,&n) == EOF)
		return false;
	for(int i = 0; i < m; i++)
		cin >> farm[i];
	col = 0;
	memset(f,-1,sizeof(f));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(farm[i][j] == '*' && f[i][j] == -1) {
				for(int k = j;farm[i][k] == '*' && k < n; k++)
					f[i][k] = col;
				col++;
			}
	row = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(farm[j][i] == '*' && f[j][i] != -1) {
				for(int k = j; farm[k][i] == '*' && k < m; k++) {
					map[f[k][i]][row] = true;
					f[k][i] = -1;
				}
				row++;
			}
	return true;
}

int main()
{
	while(input())
		printf("%d\n",MaxMatch());

	return 0;
}