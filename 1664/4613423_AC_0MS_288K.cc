#include<stdio.h>
#include<memory.h>
#define N 13
int main()
{
        int dp[N][N][N]={0};
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0; i < 11; i++)
                for(int j = 0; j < 11; j++)
                        for(int k = 0; k <= j ;k++)
                                for(int l = k; l < 11 && (j+l)<11; l++)
                                        dp[i+1][j+l][l]+=dp[i][j][k];
        int m,n,t;
        scanf("%d",&t);
        while(t--)      {
                scanf("%d%d",&m,&n);
                int res(0);
                for(int i = 0; i < N; i++)
                        res += dp[n][m][i];
                printf("%d\n",res);
        }
        return 0;
}
