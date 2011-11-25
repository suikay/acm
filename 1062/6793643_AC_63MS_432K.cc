#include <string.h>
#include <stdio.h>
#define N 101
#define INF 0x0fffffff
int odis[N][N], l[N];
int dis[N][N], shortest[N];
bool used[N];
int small(int x,int y)
{
    if(x < y)
        return x;
    return y;
}
int dijkstra(int start,int end)
{
    int min,mini;
    memset(used,false,sizeof(used));
    int n = end - start + 1;
    for(int i = start; i <= end; i++)
        shortest[i] = dis[start][i];
    used[start] = true;
    shortest[start] = INF;
    for(int i = 1; i < n; i++)
    {
        min = INF;
        mini = -1;
        for(int j = start; j <= end; j++)
            if(!used[j] && min > shortest[j])
            {
                min = shortest[j];
                mini = j;
            }
        used[mini] = true;
        for(int j = start; j <= end; j++)
            if(!used[j] && (dis[mini][j] >= 0) && 
                (min + dis[mini][j] < shortest[j]))
                shortest[j] = min + dis[mini][j];
    }

    return shortest[1];

}
bool make(int low,int m,int n)
{
    memcpy(dis,odis,sizeof(odis));
    if(l[1] < low || (l[1]-low) > m)
        return false;
    for(int i = 1; i <= n; i++)
        if(l[i] < low || (l[i] - low) > m)
            memset(dis[i],-1,sizeof(dis[i]));
    return true;
}
int main(int argc, const char *argv[])
{
    int m,n,cnt,min,max,t1,t2;
    memset(odis,-1,sizeof(odis));
    scanf("%d%d",&m,&n);
    max = -1; min = INF;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&odis[0][i],&l[i],&cnt);
        if(l[i] > max)  max = l[i];
        if(l[i] < min)  min = l[i];
        for(int j = 0; j < cnt; j++)
        {
            scanf("%d%d",&t1,&t2);
            odis[t1][i] = t2;
        }
    }
    int res = INF;
    for(int i = min; i <= max; i++)
    {
        if(make(i,m,n))
            res = small(res,dijkstra(0,n));
        if(i + m >= max)
            break;
    }
    printf("%d\n",res);
    
    return 0;
}
/*
1 2
10000 3 1
2 1000
8000 2 0
 */