#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 60000;
int n,cnt[N];
int main()
{
	int last,tmp,now,sum;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		cnt[tmp]++;
	}
	now = 0;
	sum = 0;
	for(int i = 0; i < n-1; i++) {
		while(cnt[now] == 0)
			now++;
		cnt[now]--;
		last = now;
		while(cnt[now] == 0)
			now++;
		cnt[now]--;
		sum += last + now;
		cnt[last+now]++;
	}
	cout << sum  << endl;
	return 0;
}