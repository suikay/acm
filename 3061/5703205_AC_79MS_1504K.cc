#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int arr[110000],sum[110000];
int main()
{
	int k,n,res,l,r,s;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&s);
		memset(sum,0,sizeof(sum));
		for(int i = 1; i <= n; i++) {
			scanf("%d",arr+i);
			sum[i] = sum[i-1] + arr[i];
		}
		l = r = 0;
		while(sum[r] < s)
			r++;
		if(r > n) {
			puts("0");
			continue;
		}
		res = r - l;
		while(r <= n) {
			while(sum[r]-sum[l] >= s)
				l++;
			l--;
			if(res > (r-l))
				res = r-l;
			r++;
		}
		cout << res << endl;
	}


	return 0;
}