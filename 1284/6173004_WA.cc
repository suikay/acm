#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int p[100000],pn,cnt[70000];
bool bp[70000];
int main()
{
	memset(bp,false,sizeof(bp));
	for(int i = 2; i <= 65536; i++)
		if(!bp[i]) {
			//cout << i << endl;
			for(int j = i*i; i <= 1000 && j <= 65536; j += i)
				bp[j] = true;
			cnt[i] = pn;
			p[pn++] = i;
		}
	int n;
	while(scanf("%d",&n) == 1)
		printf("%d\n",cnt[n]);


	return 0;
}
