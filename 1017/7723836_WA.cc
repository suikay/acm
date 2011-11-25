#include <stdio.h>
#include <iostream>
using namespace std;

void taketwo(int &space, int &two, int totake)
{
	if (totake > two) {
		space -= 4*totake;
		two = 0;
	} else {
		space = 0;
		two -= totake;
	}
}

void takeone(int &space, int &one)
{
	if (space >= one) {
		space -= one;
		one = 0;
	} else {
		one -= space;
		space = 0;
	}
}

int main(int argc, char *argv[])
{
	int cnt[6], sum, res, space;
	while (true)
	{
		res = sum = 0;
		for (int i = 5; i >= 0; i--) {
			scanf("%d", &cnt[i]);
			sum += cnt[i];
		}
		if (!sum)
			return 0;
		res += cnt[0];
		res += cnt[1];
		space = 11*cnt[1];
		takeone(space, cnt[5]);
		res += cnt[2];
		space = 20;
		taketwo(space, cnt[4], 5);
		takeone(space, cnt[5]);
		res += cnt[3]/4;
		if (cnt[3]%4)
		{
			res++;
			switch(cnt[3]%4) {
				case 1:
					space = 9;
					taketwo(space, cnt[4], 1);
					takeone(space, cnt[5]);
					break;
				case 2:
					space = 18;
					taketwo(space, cnt[4], 3);
					takeone(space, cnt[5]);
					break;
				case 3:
					space = 27;
					taketwo(space, cnt[4], 4);
					takeone(space, cnt[5]);
					break;
			}
		}
		res += cnt[4]/9;
		cnt[4] %= 9;
		if (cnt[4])
			res ++;
		space = cnt[4]*4;
		takeone(space, cnt[5]);
		res += cnt[5]/36;
		cnt[5] %= 36;
		takeone(cnt[5], cnt[5]);

		printf("%d\n", res);

	}
	return 0;
}
