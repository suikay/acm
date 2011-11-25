#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 110000;
int arr[N];
int main()
{
	int n,k,time;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",arr+i);
	scanf("%d",&k);
	make_heap(arr,arr+n);
	if(k == 1) {
		printf("%d\n",arr[0]);
		return 0;
	}
	k--;
	time = 0;
	while(arr[0] > time) {
		arr[0] -= k;
		pop_heap(arr,arr+n);
		push_heap(arr,arr+n);
		time++;
	}
	printf("%d\n",time);

	return 0;
}