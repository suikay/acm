#include <stdio.h>

const int N_INF = -(0x3fffffff);

int n, m, o;
int dp[3005][3005];
int next[3005][3005], next_c[3005];
int check[3005], w[3005];

int go(int root)
{
	if (root > o)
	{
		dp[root][1] = w[root];
		return 1;
	}
	int cnt = 0, tmp, v;
	for (int i = 0; i < next_c[root]; ++i)
	{
		v = next[root][i];
		tmp = go(v);
		for (int j = 0; j <= cnt; ++j)
			for (int k = 1; k <= tmp; ++k)
			{
				if (dp[root][j+k] < (dp[root][j] + dp[v][k]))
					dp[root][j+k] = dp[root][j] + dp[v][k];
			}
		cnt += tmp;
	}
	for (int i = 1; i <= cnt; ++i)
		dp[root][i] += w[root];

	return cnt;
}

int main()
{
	int tmp, num;
	scanf("%d%d", &n, &m);
	o = n - m;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = N_INF;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = 0;
	for (int i = 1; i <= n-m; ++i)
	{
		scanf("%d", &tmp);
		for (int j = 0; j < tmp; ++j)
		{
			scanf("%d", &num);
			next[i][next_c[i]++] = num;
			scanf("%d", &w[num]);
			w[num] = -w[num];
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &tmp);
		w[o+i] += tmp;
	}
	tmp = go(1);
	for (int i = tmp; i >= 0; i--)
		if (dp[1][i] >= 0)
		{
			printf("%d\n", i);
			return 0;
		}

	return 0;
}
