#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int bp[1100000],cnt[1100000];
int p[1100000],pn;
int main()
{
	int last = 0;
	for(int i = 2; i < 1100000; i++)
		if(!bp[i] && ((i-1)%4 == 0)) {
			p[pn++] = i;
			for(int j = i*i; i <= 1000 && j < 1100000; j += i)
				bp[j] = 1;
		}
	//cout << pn << endl;

	for(int i = 0; i < pn; i++) 
		for(int j = i;p[i] <= 1000000/p[j] && j < pn; j++) {
			bp[p[i]*p[j]] = 2;
		}
	for(int i = 1; i < 1100000; i+=4) {
		if(bp[i] == 2)
			last++;
		cnt[i] = last;
	}
	int n;

	while(scanf("%d",&n) && n)
		printf("%d %d\n",n,cnt[n]);

	return 0;
}
