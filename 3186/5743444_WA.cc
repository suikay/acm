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
	int n,arr[2100],l,r,res(0);
	scanf("%d",&n);
	l = 0;
	r = n-1;
	for(int i = 0; i < n; i++)
		scanf("%d",arr+i);
	for(int i = 1; i <= n; i++) 
		if(arr[r] > arr[l])
			res += i * arr[l++];
		else
			res += i*arr[r--];
	printf("%d\n",res);

	return 0;
}