#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int cnt[500];
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

//	for(int i = 0; i < pn ; i++)
//		cout << p[i] << " " ;
	while(scanf("%d%d",&n,&a) == 2)
	{
		memset(cnt,0,sizeof(cnt));
		b = n - a;
		for(int i = 1; i <= n; i++)
		{
			tmp = i;
			for(int j = 0; p[j] <= tmp && j < pn; j++)
				while(tmp && tmp%p[j] == 0)
				{
					if(i <= a)
						cnt[p[j]]--;
					if(i <= b)
						cnt[p[j]]--;
					cnt[p[j]]++;
					tmp /= p[j];
				}
		}
		unsigned long long res(1);
		for(int i = 2; i <= n; i++)
			if(cnt[i])
				res = res * (cnt[i]+1);
		printf("%llu\n",res);
	}


	return 0;
}
