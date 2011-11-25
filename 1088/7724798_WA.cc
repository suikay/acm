#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int step[102][102], height[102][102];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int r, c;
bool go()
{
	bool ok = false;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			for (int k = 0; k < 4; k++)
				if (height[i][j] > height[dx[k]+i][dy[k]+j]
					&& step[i][j] <= step[dx[k]+i][dy[k]+j])
				{
					ok = true;
					step[i][j] = step[dx[k]+i][dy[k]+j] + 1;
				}
	return ok;
}

int max()
{
	int res = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			res = (res < step[i][j])?step[i][j]:res;
	return res;
}

int main(int argc, char *argv[])
{
	scanf("%d%d", &r, &c);
	memset(height, -1, sizeof(height));

	cout << step[0][0] << endl;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			step[i][j] = 0;
			scanf("%d", &height[i][j]);
		}

	while (go());
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			cout << step[i][j] << " ";
		cout << endl;
	}

	printf("%d\n", max());

	return 0;
}

/*
3 3
1 2 3
6 5 4
7 9 9
4 4
9 9 9 9
9 1 2 9
9 4 3 9
9 9 9 9
3 3
0 0 0
0 1 0
0 0 0
*/
