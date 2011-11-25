#include <stdio.h>
#include <string.h>

bool cp[40000], ce[40000], ci[40000];

void init()
{
	memset(cp, false, sizeof(cp));
	memset(ce, false, sizeof(ce));

	for (int i = 23; i < 40000; i+= 23)
		cp[i] = true;
	for (int i = 28; i < 40000; i+= 28)
		ce[i] = true;
	for (int i = 33; i < 40000; i+= 33)
		ci[i] = true;
}

int main(int argc, char *argv[])
{
	int p, e, i, d;
	int res, c = 1;
	int pp, ee;
	init();
	while (scanf("%d%d%d%d", &p, &e, &i, &d) && p >= 0)
	{
		p %= 23; e %= 28; i %= 33;
		if (d > i)
			res = ((d - i) / 33) * 33 + i;
		else
			res = 0;
		while (res <= d || res < p || res < e || res < i)
			res += 33;
		while (true)
		{
			if (cp[res-p] && ce[res-e] && ci[res-i])
				break;
			res += 33;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",
			c++, res-d);
	}

	
	return 0;
}
