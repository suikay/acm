#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int cnt[1100000];
int main()
{
	int n,s,tmp,lsum;
	scanf("%d%d",&n,&s);
	for(int i = 0; i < n; i++) {
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	int m = s >> 1,j,res(0);
	j = 1;
	lsum = 0;
	for(int i = s-1; i > m; i--) 
		if(cnt[i]){
			for(;i+j <= s; j++)
				if(cnt[j])
					lsum += cnt[j];
			res += lsum * cnt[i];
		}
	for(; j < m; j++)
		lsum += cnt[j];
	lsum += cnt[m];
	res += ((lsum-1)*lsum) >> 1;
	cout << res << endl;

	return 0;
}