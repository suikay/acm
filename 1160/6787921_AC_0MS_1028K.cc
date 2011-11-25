#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int dp[310],arr[310];
int dis[310][310];
int main()
{
    int v,p,mid;
    scanf("%d%d",&v,&p);
    for(int i = 1; i <= v; i++)
    {
        scanf("%d",arr+i);
    }
    for(int i = 1; i <= v; i++) 
    {
        mid = i;
        for(int j = i+1; j <= v; j++) {
            if(!((j-i) & 1))
                mid++;
            dis[i][j] = dis[i][j-1] + arr[j] - arr[mid];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < p; i++)
        for(int j = v; j >= i ;j--)
            for(int k = v; k > j; k--)
                if(dp[j] + dis[j+1][k] < dp[k])
                {
                    //cout << j << " " << k << " " << dp[k] << endl;
                    dp[k] = dp[j] + dis[j+1][k];
                }
    printf("%d\n",dp[v]);

    return 0;
}
/*
10 5
1 2 3 6 7 9 11 22 44 50
*/
