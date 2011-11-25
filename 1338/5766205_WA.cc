#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool bp[1000000];
int res[2000],rn;
int main()
{
	res[1] = 1; res[2] = 2; res[3] = 3; res[4] = 4; res[5] = 5;
	rn = 6;
	for(int i = 6;i < 1000000 && rn <= 1500; i++)
		if(!bp[i]) {
			if(!(i%2) || ! (i%3) || !(i%5))
				res[rn++] = i;
			else
				for(int j = i*i; j < 1000000; j+=i)
					bp[j] = true;
		}
	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",res[n]);

	return 0;
}