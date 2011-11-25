#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int cnt[500][500];
int p[500],pn;
bool bp[500];
int main()
{
	int n,a,b,tmp;
	for(int i = 2; i < 500; i++)
		if(!bp[i]) {
			p[pn++] = i;
			for(int j = i*i; j < 500; j+=i)
				bp[j] = true;
		}

	for(int i = 2; i <= 440; i++) {
		memcpy(cnt[i],cnt[i-1],sizeof(int)*500);
		tmp = i;
		for(int j = 0; j < pn && p[j] <= tmp; j++) {
//			cout << tmp << " " << p[j] << endl;
			while(tmp && (tmp % p[j] == 0))
			{
				cnt[i][p[j]]++;
				//cout << " HE " << endl;
				tmp /= p[j];
			}
		}
//		break;
	}

	while(scanf("%d%d",&n,&a) == 2)
	{
		b = n - a;
		unsigned long long res(1);
		for(int i = 0; p[i] <= n && i < pn; i++) {
			tmp = cnt[n][p[i]]-cnt[a][p[i]]-cnt[b][p[i]];
			if(tmp)
				res = res*(tmp+1);
		}
		printf("%llu\n",res);
	}


	return 0;
}
