#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int arr[1010][1010];
int main()
{
	int k,n;
	bool v;
	while(true)
	{
		v = true;
		scanf("%d",&n);
		if(!n )
			return 0;
		for(int i = 0; i < n ;i++)
			for(int j = 0; j < n; j++)
				scanf("%d",arr[i]+j);
		for(int i = 0;v && i+1 < n; i++) {
			arr[i][0] -= arr[i+1][0];
			for(int j = 1;j < n; j++) {
				arr[i][j] -= arr[i+1][j];
				if(arr[i][j-1] != arr[i][j]) {
					v = false;
					break;
				}
			}
		}
		if(v)
			puts("homogeneous");
		else
			puts("not homogeneous");
	}

	return 0;
}