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
	int s[1000],n,sum;
	while(cin >> n) {
		if(n == 0)
			return 0;
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d",s+i);
			sum += s[i];
		}
		sort(s,s+n);
		sum -= (s[0] + s[n-1]);
		cout << sum/(n-2) << endl;
	}

	return 0;
}