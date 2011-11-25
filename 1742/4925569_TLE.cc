#include<memory.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int record[10000];
bool dp[1000000];
int main()
{
	int m,n,c,ptr,max,tmp,i;
	int a[110];
	while(true)
	{
		memset(dp,false,sizeof(dp));
		ptr = 0;
		max = 0;
		dp[0] = true;
		scanf("%d%d",&n,&m);
		if(!n && !m)
			return 0;
		for(i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&c);
			for(int j = 1; j <= c; j++){
				record[ptr++] = a[i] * j;
				c -= j;
			}
			if(c != 0)
				record[ptr++] = a[i] * c;
		}
		sort(record,record+ptr);
		for(i = 0; i < ptr; i++)
			for(int j = max; j >= 0; j--)
				if(dp[j])
				{
					tmp = j + record[i];
					if(tmp > m)
						continue;
					dp[j + record[i]] = true;
					if(tmp > max)
						max = tmp;
				}
		int res(0);
		for(i = 1; i <= m; i++)
			if(dp[i])
				res++;
		printf("%d\n",res);
	}
	return 0;
}