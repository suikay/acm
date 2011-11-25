#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
bool v[1000005];
int arr[310];
int main()
{
	int t,n,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		memset(v,false,sizeof(bool)*(arr[n-1]+1));
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++) {
				tmp = arr[j] - arr[i];
				for(int k = 1,sq = (int)sqrt(1.0*tmp); k <= sq; k++)
					if(tmp%k == 0) 
						v[k] = v[tmp/k] = true;
			}
		for(int i = 1; i < 1000000; i++)
			if(!v[i]) {
				printf("%d\n",i);
				break;
			}
	}

	return 0;
}
