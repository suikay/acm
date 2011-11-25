#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
bool v[1000000];
int arr[310];
int main()
{
	int t,n,tmp;
	scanf("%d",&t);
	while(t--)
	{
		memset(v,false,sizeof(v));
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++) {
				tmp = arr[j] - arr[i];
				for(int k = 1; k < tmp; k++)
					if(tmp%k == 0) 
						v[k] = true;
			}
		for(int i = 1; i < 1000000; i++)
			if(!v[i]) {
				printf("%d\n",i);
				break;
			}
	}

	return 0;
}
