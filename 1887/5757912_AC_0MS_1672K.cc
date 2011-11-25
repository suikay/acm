#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int N = 1000000;
int arr[N];
bool v[N];
int main()
{
	int n,now,res,k;
	k = 0;
	while(true)
	{
		memset(v,false,sizeof(v));
		n = 0;
		res = 0;
		while(scanf("%d",arr+n))
			if(arr[n] == -1)
				break;
			else
				n++;
		if(n == 0)
			return 0;
		for(int i = 0; i < n; i++) {
			if(v[i])
				continue;
			now = arr[i];
			res++;
			v[i] = true;
			for(int j = i+1; j < n; j++)
				if(arr[j] > now && !v[j])
				{
					now = arr[j];
					v[j] = true;
				}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++k,res);
	}

	return 0;
}