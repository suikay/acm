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
	scanf("%d",&n);
	sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d",arr+i);
		arr[i] *= -1;
	}
	now = 0;
	sum = 0;
	pt = n-1;
	make_heap(arr,arr+n);
	for(int i = 0; i < n-1; i++) {
		last = arr[0];
		pop_heap(arr,arr+pt+1);
		now = arr[0];
		pop_heap(arr,arr+pt);
		pt--;
		sum += (now + last);
		arr[pt] = now + last;
		push_heap(arr,arr+pt+1);
	}
	cout << -sum << endl;
	return 0;
}