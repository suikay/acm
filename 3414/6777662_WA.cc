#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a,b,c,d;
bool check[110][110];
int path[10000],deep;
int min(int x,int y) {
    if(x < y)
        return x;
    return y;
}
bool dfs(int x,int y)
{
    cout << x << " v " << y << " " << d << endl;
    check[x][y] = true;
    if(x == d || y == d)
        return true;
    if(x < a && !check[a][y]) {
        path[deep++] = 0;
        if(dfs(a,y))
            return true;
        deep--;
    }
    if(y < b && !check[x][b]) {
        path[deep++] = 1;
        if(dfs(x,b))
            return true;
        deep--;
    }
    c = min(y,a-x);
    if(c && !check[x+c][y-c]) {
        path[deep++] = 2;
        if(dfs(x+c,y-c))
            return true;
        deep--;
    }
    c = min(x,b-y);
    if(c && !check[x-c][y+c]) {
        path[deep++] = 3;
        if(dfs(x-c,y+c))
            return true;
        deep--;
    }
    if(x && !check[0][y]) {
        path[deep++] = 4;
        if(dfs(0,y))
            return true;
        deep--;
    }
    if(y && !check[x][0]) {
        path[deep++] = 5;
        if(dfs(x,0))
            return true;
        deep--;
    }
    
    return false;
}
int main(int argc, const char *argv[])
{
    scanf("%d%d%d",&a,&b,&d);
    deep = 0;
    memset(check,false,sizeof(check));
    if(dfs(0,0)) {
        printf("%d\n",deep);
        for(int i = 0; i < deep; i++)
            switch(path[i]) {
                case 0: puts("FILL(1)"); break;
                case 1: puts("FILL(2)"); break;
                case 2: puts("POUR(2,1)"); break;
                case 3: puts("POUR(1,2)"); break;
                case 4: puts("DROP(1)");   break;
                case 5: puts("DROP(2)");   break;
            }
    }
    else
        puts("impossible");
    
    return 0;
}