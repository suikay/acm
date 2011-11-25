#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 410;
int map[N][N],match[N],n;
bool v[N];

bool dfs(int x)
{
	for(int i = 1; i <= n; i++)
		if(!v[i] && map[x][i]) {
			v[i] = true;
			if(match[i] == -1 || dfs(match[i])) {
				match[i] = x;
				return true;
			}
	}
	return false;
}

int maxmatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 1; i <= n; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

void input()
{
	char m[45][15];
	int x,y,mm[45][15];
	memset(mm,-1,sizeof(mm));
	cin >> x >> y;
	for(int i = 0; i < x; i++)
		cin >> m[i];
	n = 0;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			if(m[i][j] == '*')
				mm[i+1][j+1] = ++n;
	for(int i = 1; i <= x; i++)
		for(int j = 1; j <= y; j++) 
			if(mm[i][j] > 0){
				int now = mm[i][j];
				if(mm[i-1][j] > 0) map[now][mm[i-1][j]] = 1;
				if(mm[i+1][j] > 0) map[now][mm[i+1][j]] = 1;
				if(mm[i][j-1] > 0) map[now][mm[i][j-1]] = 1;
				if(mm[i][j+1] > 0) map[now][mm[i][j+1]] = 1;
			}
}

int main()
{
	int k;
	cin >> k;
	while(k--) {
		input();
		cout << n - maxmatch()/2  << endl;
	}


	return 0;
}