#include <stdio.h>
#include <string.h>

int dp[102][102];
int m[102][102];
int b[102];

int abs(int x) {
	if (x < 0)
		return -x;
	return x;
}

char chFromInt(int x) {
	switch (x) {
		case 1: return '(';
		case -1: return ')';
		case 2: return '[';
		case -2: return ']';
	}
	return ' ';
}

void print(int beg, int end)
{
	if (beg >= end) return ;
	if (beg + 1 == end)
	{
		printf("%c%c", chFromInt(abs(b[beg])), chFromInt(-abs(b[beg])));
		return ;
	}
	if (m[beg][end] == -1)
	{
		printf("%c", chFromInt(b[beg]));
		print(beg+1, end-1);
		printf("%c", chFromInt(b[end-1]));
		return;
	}
	print(beg, m[beg][end]);
	print(m[beg][end], end);
}

int go(int beg, int end)
{
	int tmp;
	if (beg >= end)
		return 0;
	if (beg + 1 == end)
		return 1;
	if (dp[beg][end] != -1)
		return dp[beg][end];
	if (b[beg] > 0 && b[end-1] < 0 && b[beg] + b[end-1] == 0)
	{
		dp[beg][end] = go(beg+1, end-1);
		m[beg][end] = -1;
	}
	for (int i = beg+1; i < end; ++i)
	{
		tmp = go(beg, i) + go(i, end);
		if (dp[beg][end] == -1 || dp[beg][end] >= tmp)
		{
			dp[beg][end] = tmp;
			m[beg][end] = i;
		}
	}
	return dp[beg][end];
}

int main()
{
	char line[102];
	gets(line);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < strlen(line); ++i)
	{
		if (line[i] == '(')
			b[i] = 1;
		if (line[i] == ')')
			b[i] = -1;
		if (line[i] == '[')
			b[i] = 2;
		if (line[i] == ']')
			b[i] = -2;
	}
	go(0, strlen(line));
	//printf("%d\n", dp[0][strlen(line)]);
	print(0, strlen(line));
	puts("");

	return 0;
}