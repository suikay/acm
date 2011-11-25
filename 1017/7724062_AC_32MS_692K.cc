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
	int cnt[7], sum, res, space;
	while (true)
	{
		res = sum = 0;
		for (int i = 1; i <= 6; i++) {
			scanf("%d", &cnt[i]);
			sum += cnt[i];
		}
		if (!sum)
			return 0;
		res += cnt[6] + cnt[5] + cnt[4];
		cnt[1] -= cnt[5]*11;
		if (cnt[4]*5 < cnt[2]) {
			cnt[2] -= cnt[4]*5;
		} else {
			cnt[1] -= (cnt[4]*5 - cnt[2]);
			cnt[2] = 0;
		}
		res += cnt[3]/4;
		cnt[1] = max(0, cnt[1]);
		cnt[2] = max(0, cnt[2]);
		cnt[3] %= 4;
		if (cnt[3])
			res++;
		switch(cnt[3]) {
			case 1:
				if (cnt[2] > 5) {
					cnt[2] -= 5;
					cnt[1] -= 7;
				} else {
					cnt[1] -= (27 - 4*cnt[2]);
					cnt[2] = 0;
				}
				break;
			case 2:
				if (cnt[2] > 3) {
					cnt[2] -= 3;
					cnt[1] -= 6;
				} else {
					cnt[1] -= (18 - 4*cnt[2]);
					cnt[2] = 0;
				}
				break;
			case 3:
				if (cnt[2] >= 1) {
					cnt[2] -= 1;
					cnt[1] -= 5;
				} else {
					cnt[1] -= 9;
					cnt[2] = 0;
				}
				break;
		}
		cnt[2] = max(cnt[2], 0);
		cnt[1] = max(cnt[1], 0);
		res += (35+cnt[2]*4+cnt[1])/36;

		printf("%d\n", res);

	}
	return 0;
}
