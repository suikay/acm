#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char str[200];
char stack[110];
int dp[110][110],path[110][110];
int top;

char p(char x)
{
	if(x == ')')
		return '(';
	return '[';
}

char pp(char x)
{
	if(x == '(' )
		return ')';
	return ']';
}

bool left(char x)
{
	return (x == '(' || x == '[');
}

int dfs(int x,int y)
{
	int	tmp;
	if(x > y)
		return 0;
	if(x == y)
		return dp[x][y] = 1;
	if(path[x][y] != -1)
		return dp[x][y];
	if(left(str[x]) && (pp(str[x]) == str[y])) {
		path[x][y] = 1000;
		dp[x][y] = dfs(x+1,y-1);
	}
	else {
		for(int i = x; i < y; i++) {
			tmp = dfs(x,i)+dfs(i+1,y);
			if(dp[x][y] > tmp) {
				path[x][y] = i;
				dp[x][y] = tmp;
			}
		}
	}

	return dp[x][y];
}

void print(int x,int y)
{
	if(x > y)
		return;
	if(x == y) {
		if(left(str[x])) {
			putchar(str[x]);
			putchar(pp(str[x]));
		}else {
			putchar(p(str[x]));
			putchar(str[x]);
		}
		return;
	}
	if(path[x][y] == 1000) {
		putchar(str[x]);
		print(x+1,y-1);
		putchar(str[y]);
		return;
	}
	print(x,path[x][y]);
	print(path[x][y]+1,y);
}

int main()
{
	memset(dp,0x7f,sizeof(dp));
	memset(path,-1,sizeof(path));
	gets(str);
	dfs(0,strlen(str)-1);
	print(0,strlen(str)-1);
	puts("");

	return 0;
}
/*
()][)[(][])
*/