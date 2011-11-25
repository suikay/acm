#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 31000;
int main()
{
	int cnt[N],n,l,_min,tmp,sum,res;
	while(cin >> n >> l)
	{
		sum = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			cnt[tmp % l]++;
			sum += tmp%l;
		}
		_min = sum;
		res = 0;
		for(int i = 1; i < l; i++) {
			sum += n;
			sum -= cnt[l-i]*l;
			if(sum < _min) {
				res = i;
				_min = sum;
			}
		}
		cout << res << endl;
	}
	
	return 0;
}