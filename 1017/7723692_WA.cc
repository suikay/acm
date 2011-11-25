#include <stdio.h>
#include <iostream>
using namespace std;

void taketwo(int &space, int &two, int totake)
{
	if (totake > two) {
		space -= 8*totake;
		two = 0;
	} else {
		space = 0;
		two -= totake;
	}
}

void takeone(int &space, int &one, int totake)
{
	if (totake >= one) {
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
		res = 0;
		sum = 0;
		for (int i = 0; i < 6; i++) {
			scanf("%d", &cnt[5-i]);
			sum += cnt[5-i];
		}
		if (sum == 0)
			return 0;
		res = cnt[0];
		res += cnt[1];
		for (int i = 0; i < cnt[1]; i++)
		{
			space = 91;
			takeone(space, cnt[5], space);
		}
		res += cnt[2];
		for (int i = 0; i < cnt[2]; i++)
		{
			space = 152;
			taketwo(space, cnt[4], 19);
			takeone(space, cnt[5], space);
		}
		res += cnt[3] / 8;
		if (cnt[3] % 8)
		{
			res++;
			switch(cnt[3] % 8) {
				case 1: 
					space = 6*6*6 - 3*3*3;
					taketwo(space, cnt[4], 19);
					break;
				case 2:
					space = 6*6*6 - 3*3*3*2;
					taketwo(space, cnt[4], 15);
					break;
				case 3:
					space = 6*6*6 - 3*3*3*3;
					taketwo(space, cnt[4], 11);
					break;
				case 4:
					space = 6*6*6 - 3*3*3*4;
					taketwo(space, cnt[4], 9);
					break;
				case 5:
					space = 6*6*6 - 3*3*3*5;
					taketwo(space, cnt[4], 5);
					break;
				case 6:
					space = 6*6*6 - 3*3*3*6;
					taketwo(space, cnt[4], 3);
					break;
				case 7:
					space = 6*6*6 - 3*3*3*7;
					taketwo(space, cnt[4], 1);
					break;
			}
			takeone(space, cnt[5], space);
		}
		res += cnt[4]/27;
		if (cnt[4] % 27) {
			res++;
			space = 6*6*6 - 2*2*2*(cnt[4]%27);
		} else 
			space = 0;
		takeone(space, cnt[5], space);
		res += cnt[5] / (6*6*6);
		if (cnt[5] % (6*6*6))
			res++;
		printf("%d\n", res);

	}
	return 0;
}
