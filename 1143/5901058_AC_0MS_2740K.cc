#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[1<<19];
bool take(int x,int v)
{
    int vp(v|(1<<(x-2)));
    for(int i = 2; i < 20; i++) {
        if(vp &(1 << i-2))
            for(int j = i+x; j < 21; j+=x)
                vp |= (1 << j-2);
    }
    if(dp[vp] != -1)
        return dp[vp] == 1;
    for(int k = 2; k < 21; k++)
        if(!(vp & (1 << k-2)))
            if(take(k,vp)) {
                dp[vp] = 0;
                return false;
            }
    dp[vp] = 1;
    return true;
}
int main() {
    int n,cnt(1),tmp,v;
    vector<int>res;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n) && n)
    {
        res.resize(0);
        v = (1<<19)-1;
        dp[v] = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d",&tmp);
            v ^= (1 << tmp-2);
        }
        for(int i = 2; i < 21; i++)
            if(!(v&(1<<i-2)) && take(i,v))
                res.push_back(i);
        if(res.empty()) {
            printf("Test Case #%d\n",cnt++);
            printf("There's no winning move.\n\n");
            continue;
        }
        printf("Test Case #%d\nThe winning moves are:",cnt++);
        for(int i = 0; i < res.size(); i++)
            printf(" %d",res[i]);
        printf("\n\n");
    }

    return 0;
}
// 19 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

