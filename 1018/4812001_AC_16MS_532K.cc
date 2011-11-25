#include<memory.h>
#include<stdio.h>
#define NIL 0x7f7f7f7f
int  dp[110][500];
int main()
{
	int t,n,mi,max,_max,tmp,p;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0x0f,sizeof(dp));
		scanf("%d",&n);
		dp[0][499] = 0;
		//printf("%d\n",dp[1][1]);
		max = 499;
		for(int i = 1; i <= n; i++)
		{
			_max = 0;
			scanf("%d",&mi);
			for(int j = 0; j < mi; j++){
				scanf("%d%d",&tmp,&p);
				if(_max < tmp)
					_max = tmp;
				for(int k = 0; k <= tmp; k++)
					if(dp[i-1][k] + p < dp[i][k])
						dp[i][k] = dp[i-1][k] + p;
				for(int k = tmp + 1; k <= max; k++)
					if(dp[i-1][k] + p < dp[i][tmp])
						dp[i][tmp] = dp[i-1][k] + p;
			}
			max = _max;
		}
		double res = 0;
		for(int i = 1; i <= max; i++)
			if(res < (1.0*i/dp[n][i]))
				res = 1.0*i/dp[n][i];
		printf("%.3f\n",res);
	}
	return 0;
}
