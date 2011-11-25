#include<memory.h>
#include<stdio.h>
	int record[1000000];
	bool dp[110000];
int main()
{
	int cash,n,i,j,ptr,res;
	int max,worth,count,tmp;
	while(scanf("%d",&cash) != EOF)
	{
		memset(dp,false,sizeof(dp));
		dp[0] = true;
		max = 0;
		ptr = 0;
		res = 0;
		scanf("%d",&n);
		for(i = 0 ; i < n; i++)
		{
			scanf("%d%d",&count,&worth);
			for(j = 1; j <= count; j *= 2 )
				record[ptr++] = worth * j;
			j = j/2;
			if(count - j)
				record[ptr++] = worth * (count - j);
		}
		for(int i = 0; i < ptr; i++)
			for(int j = max; j  >= 0; j--)
				if(dp[j])	{
					tmp = j + record[i];
					if(tmp > cash)
						continue;
					if(tmp > max)
						max = tmp;
					dp[tmp] = true;
				}
		printf("%d\n",max);
	}
	return 0;
}