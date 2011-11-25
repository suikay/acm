#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int arr[1000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",arr+i);
	sort(arr,arr+n);
	int res(0);
	for(int i = 0; i <= n/2; i++)
		res += arr[i]/2+1;
	cout << res << endl;


	return 0;
}
