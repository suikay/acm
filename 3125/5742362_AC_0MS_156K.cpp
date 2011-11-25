#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int cnt[10],q[110],arr[110];
bool v[110];
int main()
{
	int n,p,now,t,k;
	scanf("%d",&k);
	while(k--)
	{
		t = now = 0;
		memset(cnt,0,sizeof(cnt));
		memset(v,false,sizeof(v));
		scanf("%d%d",&n,&p);
		for(int i = 0; i < n; i++) {
			scanf("%d",arr+i);
			cnt[arr[i]]++;
		}
		for(int i = 9; i >= 0; i--) {
			for(int j = 0; j < cnt[i]; j++) {
				while(v[now] || arr[now] != i) {
					now++;
					if(now == n)
						now = 0;
				}
				v[now] = true;
				t++;
				if(now == p)
					goto x;
			}
		}
x:		printf("%d\n",t);
	}
	return 0;
}