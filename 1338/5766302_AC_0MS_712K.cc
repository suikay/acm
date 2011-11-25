#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
set<long long> x;
long long res[2000],n,now;
int main()
{
	x.insert(1);
	for(int i = 1; i <= 1500; i++) {
		now = *(x.begin());
		res[i] = now;
		x.insert(now*2); x.insert(now*3); x.insert(now*5);
		x.erase(now);
	}
	while(scanf("%d",&n) && n)
		printf("%lld\n",res[n]);

	return 0;
}