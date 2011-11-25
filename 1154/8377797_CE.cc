#include <stdio.h>
#include <map>
using namespace std;
int m[23][23];
int dirx[] = {-1, 0, 1, 0}, diry[] = {0, -1, 0, 1};
int dfs(int x, int y, int mask)
{
	int res = 0, tmp;
	mask |= m[x][y];
	for (int i = 0; i < 4; ++i)
		if (!(mask & m[dirx[i]+x][diry[i]+y]))
		{
			tmp = dfs(dirx[i]+x, diry[i]+y, mask);
			res = (res > tmp)? res : tmp;
		}
	return res + 1;
}

int main()
{
	int r, c, tmp;
	scanf("%d%d%*c", &r, &c);
	memset(m, -1, sizeof(m));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; ++j)
		{
			tmp = getchar();
			m[i][j] = 1 << (tmp - 'A');
		}
		getchar();
	}
	printf("%d\n", dfs(1, 1, 0));

	return 0;
}