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
const int N = 20;
int m[N][N];
int v[N][N];
int dirx[] = {-1,1,0,0,-1,1},diry[] = {-1,1,-1,1,0,0};
int n,c;
bool valid(int x,int y)
{
    return (y <= x && x > 0 && x <= n && y > 0);
}

int dfs(int x,int y,int num,int key)
{
    int res(0),tmp(0),xx,yy;
    v[x][y] = key;
    for(int i = 0; i < 6; i++) {
        xx = x+dirx[i]; yy = y+diry[i];
        if(valid(xx,yy))
            if(!v[xx][yy]) {
                if(m[xx][yy] == num) {
                    tmp = dfs(xx,yy,num,key);
                    if(tmp == 0)
                        return 0;
                    else
                        res += tmp;
                } else if(m[xx][yy] == 0)
                    return 0;
            } else
                if(v[xx][yy] != key && m[xx][yy] == c && num == c)
                    return 0;
    }
    return res+1;
}

int main() {
    int xx,yy,tmp,res,key;
    //freopen("in","r",stdin);
    while(scanf("%d%d",&n,&c)&&n && c) {
        res = -1000;
        memset(v,false,sizeof(v));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                scanf("%d",&m[i][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                if(m[i][j] == 0) {
                    tmp = 0;
                    key = i*n+j;
                    v[i][j] = key;
                    for(int k = 0; k < 6; k++) {
                        xx = i+dirx[k]; yy = j+diry[k];
                        if(valid(xx,yy) && !v[xx][yy] && m[xx][yy] != c && m[xx][yy])
                            tmp += dfs(xx,yy,m[xx][yy],key);
                    }
                    v[i][j] = false;
                    m[i][j] = c;
                    tmp += -dfs(i,j,c,key);
                    if(tmp > res)
                        res = tmp;
                }
            cout << res << endl;
    }

    return 0;
}


