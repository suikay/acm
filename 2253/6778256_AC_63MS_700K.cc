#include <math.h>
#include <stdio.h>
#define N 210
double dis[N][N];
double longest[N];
int n,x[N],y[N];
double max(double x,double y)
{
    if(x > y)
        return x;
    return y;
}
double DIS(int i, int j)
{
    return sqrt(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))*1.0);
}
void dfs(int x,double l)
{
    for(int i = 0; i < n; i++)
    {   
        double m = max(l,dis[x][i]);
        if(longest[i] > m)
        {
                longest[i] = m;
                dfs(i,m);
        }
    }

}
int main(int argc, const char *argv[])
{
    int cnt = 1;
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; i++) {
            scanf("%d%d",x+i,y+i);
            longest[i] = 10e10;
        }
        longest[0] = 0.0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n ; j++)
                dis[i][j] = dis[j][i] = DIS(i,j);
        dfs(0,0.0);
        printf("Scenario #%d\nFrog Distance = ",cnt++);
        printf("%.3f\n\n",longest[1]);
    }
    
    return 0;
}