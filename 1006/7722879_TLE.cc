#include <stdio.h>

int main(int argc, char *argv[])
{
	int p, e, i, d;
	int res, c = 1;
	while (scanf("%d%d%d%d", &p, &e, &i, &d) && p >= 0)
	{
		p %= 23; e %= 28; i %= 33;
		if (d > i)
			res = ((d - i) / 33) * 33 + i;
		else
			res = 0;
		while (res <= d)
			res += 33;
		while (true)
		{
			if (!((res - p)%23) && !((res - e)%28)
					&& !((res - i)%33))
				break;
			res += 33;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",
			c++, res-d);
	}

	
	return 0;
}
