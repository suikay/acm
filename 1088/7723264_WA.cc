#include <stdio.h>

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
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d", &height[i][j]);

	while (go());
	printf("%d\n", max());

	return 0;
}
