#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 40000;
int n,cnt[N],arr[N];
int main()
{
	int last,tmp,now,pt;
	long long sum ;
	while(scanf("%d",&n) != EOF)
	{
		sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d",arr+i);
			arr[i] *= -1;
		}
		now = 0;
		sum = 0;
		pt = n;
		for(int i = 0; i < n-1; i++) {
			make_heap(arr+2*i,arr+pt);
			last = arr[2*i];
			make_heap(arr+2*i+1,arr+pt);
			now = arr[2*i+1];
			sum += (now + last);
			arr[pt++] = now + last;
		}
		cout << -sum << endl;
	}
	return 0;
}