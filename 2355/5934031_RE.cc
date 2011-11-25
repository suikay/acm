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
const int N = 11000;
const int INF = 0x7f7f7f7f;
int arr[N],pos[N],dp[N];
int n,c1,c2,c3,l1,l2,l3,s,t;
int get(int x)
{
    int l = s, r = t;
    int mid=(s+t)>>1;
    while(l < r) {
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            r = mid;
        else
            l = mid+1;
        mid = (l+r) >> 1;
    }
    while(arr[mid] < x)
        mid++;
    while(arr[mid] > x)
        mid--;
    return mid;
}
void init()
{
    scanf("%d%d%d",&l1,&l2,&l3);
    scanf("%d%d%d",&c1,&c2,&c3);
    scanf("%d",&n);
    scanf("%d%d",&s,&t);
    for(int i = 2; i <= n; i++)
        scanf("%d",&arr[i]);
}
inline int _min(int &x,int y)
{
    return (x>y)?y:x;
}
int main() {
    int g1,g2,g3;
    init();
    memset(dp,0x7f,sizeof(dp));
    dp[s] = 0;
    for(int i = s; i < t; i++)
        if(dp[i] < INF) {
            g1 = get(arr[i]+l1);
            dp[g1] = _min(dp[g1],dp[i]+c1);
            g2 = get(arr[i]+l2);
            dp[g2] = _min(dp[g2],dp[i]+c2);
            g3 = get(arr[i]+l3);
            dp[g3] = _min(dp[g3],dp[i]+c3);
        }
    printf("%d\n",dp[t]);

    return 0;
}
/*
3 6 8 20 30 40
7
1 7
3
7
8
13
15
23
 **/

