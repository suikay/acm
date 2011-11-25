#include<stdio.h>
#define N 11
int main()
{
        int dp[N][N][N];
        dp[0][0][0] = 1;
        for(int i = 0; i < N-1; i++)
                for(int j = 0; j < N-1; j++)
                        for(int k = 0; k < N-1 ;k++)
                                for(int l = k; l < N-1 && (j+l)<N; l++)
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
