#include <string.h>
#include <stdio.h>
#define N 110000
bool v[N];
int arr[N];
int main()
{
	int t, n, cnt, now, res;
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		memset(v,false,sizeof(v));
		scanf("%d",&n);
		for(int i = 1 ;i <= n; i++)
			scanf("%d",&arr[i]);
		for(int i = 1; i <= n; i++)
			if(arr[i] != i && !v[i]) 
			{
				now = i; cnt = 0;
				do {
					v[now] = true;
					now = arr[now];
					cnt++;
				}while(!v[now]);
				res += cnt-1;
			}
		printf("%d\n",res);
	}
	return 0;
}