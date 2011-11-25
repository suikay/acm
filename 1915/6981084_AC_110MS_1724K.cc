#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int d[310][310];
int l;

bool legal(int x, int y, int s)
{
    //cout << " L " << x << " " << y << " " << s << endl;
    if (x >= 0 && x < l && y >= 0 && y < l && d[x][y] > (s+1)) {
        //cout << x << ":" << y << ":" << s+1 << endl;
        d[x][y] = s + 1;
        return true;
    }
    return false;
}

int dirx[] = {-1, -1, 1, 1, -2, -2, 2, 2}, diry[] = {2, -2, 2, -2, -1, 1, -1, 1};
int topx[100000], topy[100000], q, h;
int tx, ty;
int bfs(int x, int y, int xx, int yy)
{
    h = q = 0;
    d[x][y] = 0;
    topx[q] = x;
    topy[q++] = y;
    ////cout << " IN " << xx << " " << yy << endl;
    while (h < q)
    {
        tx = topx[h];
        ty = topy[h++];
        //cout << tx << ty << endl;
        if (tx == xx && ty == yy)
            return d[xx][yy];
        for(int i = 0; i < 8; i++) 
            if (legal(tx+dirx[i], ty+diry[i], d[tx][ty])) {
                topx[q] = tx + dirx[i];
                topy[q++] = ty + diry[i];
            }
    }
    return 100000;
}

int
main(int argc, char *argv[])
{
    int n;
    int x, y, xx, yy;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        memset(d, 0x1f, sizeof(d));
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        printf("%d\n", bfs(x, y, xx, yy));
    }

    return 0;
}
