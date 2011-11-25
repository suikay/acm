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
	int n,k,tmp,now,s,sum,last;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&s);
		now = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i < n; i++) {
			scanf("%d",&tmp);
			if(tmp <= 0)
				continue;
			cnt[tmp]++;
		}
		last = 0;
		sum = 0;
		for(int i = 10000;s && i > 0; i--) {
			if(cnt[i] > 0) {
				if(sum + cnt[i]*i >= s) {
					cnt[i] = (s-sum+i-1)/i;
					last += cnt[i];
					s = 0;
				}
				else {
					sum += cnt[i]*i;
					last += cnt[i];
				}
			} else {
				sum = 0;
				last = 0;
			}
		}
		if(s == 0)
			cout << last << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}