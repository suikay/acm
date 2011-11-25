#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n,arr[60],res,a,b,tmp;
	while(scanf("%d",&n) && n)
	{
		res = 0;
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++) {
				a = arr[i]; b = arr[j];
				while(a % b) {
					tmp = a % b;
					a = b;
					b = tmp;
				}
				if(b == 1)
					res++;
			}
//		cout << res << endl;
		if(res) {
			double p = n*(n-1)*3.0;
			p /= res;
			printf("%.6lf\n",sqrt(p));
		}
		else
			puts("No estimate for this data set.");
	}

	return 0;
}
