#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char buffer[100];
int cnt[6000];
int main()
{
	int n, k, p, tmp;
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for(int i = 0; i < n; i++) {
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	for(int i = 1; i <= 5000; i++)
		cnt[i] += cnt[i-1];
	scanf("%s",buffer);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&p);
		for(int i = 5000; i >= 0; i--)
			if(cnt[i] < p) {
				printf("%d\n",i+1);
				break;
			}
	}

	return 0;
}
