#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 1100;
int map[N][N],match[N],n,sum;
bool v[N],ch[N];

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
	memset(ch,false,sizeof(false));
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			if(map[i][j] && match[j] == -1) {
				match[j] = i;
				ch[i] = true;
				break;
			}
	for(int i = 1; i <= n; i++) {
		memset(v,false,sizeof(v));
		if(ch[i] || dfs(i))
			cnt++;
	}
	return cnt;
}

void input()
{
	int m[35][35];
	int a,b,c,x,y;
	bool ch[35][35];
	scanf("%d%d%d",&a,&b,&c);
	memset(m,-1,sizeof(m));
	memset(ch,false,sizeof(ch));
	memset(map,0,sizeof(map));
	for(int i = 0; i < c; i++) {
		scanf("%d%d",&x,&y);
		ch[y][x]  = true;
	}
	n = 0;
	sum = a*b;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			if(!ch[i][j])
				m[i][j] = ++n;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++) 
			if(!ch[i][j]) {
				int now = m[i][j];
				if(!ch[i-1][j]) map[now][m[i-1][j]] = 1;
				if(!ch[i+1][j]) map[now][m[i+1][j]] = 1;
				if(!ch[i][j+1]) map[now][m[i][j+1]] = 1;
				if(!ch[i][j-1]) map[now][m[i][j-1]] = 1;
			}
}
		

int main()
{
	input();
	if(n % 2)
		printf("NO\n");
	else {
		int now = maxmatch();
		if(now==n)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}