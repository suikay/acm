#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int arr[14];
int main()
{
	int k,n,now;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		now = 0;
		memset(arr,0,sizeof(arr));
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < i; j++) {
				while(arr[now] != 0)
					now = (now+1) % n;
				now = (now+1)%n;
				while(arr[now] != 0)
					now = (now+1) % n;
			}
			arr[now] = i;
		}
		for(int i = 0; i < n; i++) {
			printf("%d",arr[i]);
			if(i == n-1)
				putchar('\n');
			else
				putchar(' ');
		}
	}

	return 0;
}