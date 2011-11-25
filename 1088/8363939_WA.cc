#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
    int h;
    bool operator<(const Point& p) const {
        return h > p.h;
    }
};

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int he[102][102], dp[102][102];

int main()
{
    int m,n,res(0);
    Point p;
    vector<Point> vp;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1;j <= m; j++)
        {
            scanf("%d", &(he[i][j]));
            p.x = i;
            p.y = j;
            p.h = he[i][j];
            vp.push_back(p);
        }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size(); i++)
    {
        m = vp[i].x; n = vp[i].y;
        if (dp[m][n] > res)
            res = dp[m][n];
        if (he[m][n] > he[m-1][n])
            dp[m-1][n] = max(dp[m-1][n], dp[m][n]+1);
        if (he[m][n] > he[m+1][n])
            dp[m+1][n] = max(dp[m+1][n], dp[m][n]+1);
        if (he[m][n] > he[m][n-1])
            dp[m][n-1] = max(dp[m][n-1], dp[m][n]+1);
        if (he[m][n] > he[m][n+1])
            dp[m][n+1] = max(dp[m][n+1], dp[m][n]+1);
    }
    printf("%d\n", res+1);

    return 0;
}
