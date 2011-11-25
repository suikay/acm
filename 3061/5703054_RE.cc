#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int cnt[11000];
int main()
{
	int n,k,tmp,now,s;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&s);
		now = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i < n; i++) {
			scanf("%d",&tmp);
			cnt[tmp]++;
		}
		for(int i = 10000;s && i >= 0; i--) {
			if((s+i-1)/i <= cnt[i]) {
				now += (s+i-1)/i;
				s = 0;
			} else {
				now += cnt[i];
				s -= cnt[i] * i;
			}
		}
		if(s == 0)
			cout << now << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}