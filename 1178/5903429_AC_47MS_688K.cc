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
const int N = 8;
const int INF = 999999;
int dp[N][N][N][N];
int dirx[] = {-2,-2,-1,-1,1,1,2,2},diry[] = {1,-1,-2,2,2,-2,-1,1};
inline bool valid(int x,int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
void dfs(int ox,int oy,int x,int y,int step)
{
    int xx,yy;
    for(int i = 0; i < 8; i++) {
        xx = x + dirx[i]; yy = y + diry[i];
        if(valid(xx,yy) && dp[ox][oy][xx][yy] > step+1) {
            dp[ox][oy][xx][yy] = step+1;
            dfs(ox,oy,xx,yy,step+1);
        }
    }
}
int lx[N*N],ly[N*N];
int main()
{
    int xx,yy,kx,ky,tmp,res,_min,dis,dd;
    char p[1000];
    memset(dp,0x7f,sizeof(dp));
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            dp[i][j][i][j] = 0;
            dfs(i,j,i,j,0);
        }
    while(cin >> p)
    {
        kx = p[0]-'A'; ky = p[1]-'1';
        int pn = 0;
        for(int i = 2; i < strlen(p); i += 2) {
            if(p[i] < 'A' || p[i] > 'H')
                break;
            lx[pn] = p[i]-'A'; ly[pn] = p[i+1]-'1';
            pn++;
        }
        if(pn == 0) {
            printf("0\n");
            return 0;
        }
        res = INF;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                for(int p = 0; p < pn; p++)
                {
                    tmp = 0;
                    for(int k = 0; k < pn; k++)
                        if(p == k)
                            continue;
                        else
                            tmp += dp[i][j][lx[k]][ly[k]];
                    _min = INF;
                    for(int x = kx-4; x <= kx+4; x++)
                        for(int y = ky-4; y <= ky+4; y++)
                            if(valid(x,y)) 
                                _min = min(_min,dp[i][j][x][y]+dp[x][y][lx[p]][ly[p]]+\
                                        max(abs(x-kx),abs(y-ky)));
                    tmp += _min;
                    res = min(res,tmp);
                    if(res < 0)
                        res = res;
                }
            cout << res << endl;
    }

    return 0;
}
// B4A1C5
