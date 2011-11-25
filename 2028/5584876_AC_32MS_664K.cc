#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int cnt[110],m,n,k,i,tmp;
	while(cin >> n >> m)
	{
		if(n == 0)
			return 0;
		memset(cnt,0,sizeof(cnt));
		for(i = 0; i < n; i++)
		{
			cin >> k;
			for(int j = 0; j < k; j++) 
			{
				cin >> tmp;
				cnt[tmp]++;
			}
		}
		int pp = 0,res;
		for(i = 1; i <= 100; i++) 
			if(cnt[i] > pp) {
				pp = cnt[i];
				res = i;
			}
		if(pp >= m)
			cout << res << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}