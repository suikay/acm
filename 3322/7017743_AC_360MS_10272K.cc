#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int N = 500;
char m[N+1][N+1];
bool v[N+1][N+1][3];
int r, c;
int orix, oriy, orid;

void output()
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << (int)m[i][j] << " ";
        cout << endl;
    }

}

bool input()
{
    char ch;

    memset(v, false, sizeof(v));
    scanf("%d%d\n", &r, &c);
    if (!r && !c)
        return false;
    orix = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ch = getchar();
            if (ch == '#') 
                m[i][j] = 0;
            else if (ch == 'X') {
                if (orix != -1) {
                   if (orix == i)
                       orid = 1;
                   else
                       orid = 2;
                } else {
                    orix = i;
                    oriy = j;
                    orid = 0;
                }
                m[i][j] = 1;
            } else if (ch == 'E')
                m[i][j] = -1;
            else if (ch == 'O')
                m[i][j] = 2;
            else
                m[i][j] = 1;
        }
        ch = getchar();
    }
    return true;
}


int qx[N*N*3], qy[N*N*3], qd[N*N*3], qs[N*N*3], h, t;
int bfs()
{
    int tx, ty, ts, td;

    h = t = 0;
    qx[t] = orix;
    qy[t] = oriy;
    qs[t] = 0;
    qd[t++] = orid;
    v[orix][oriy][orid] = true;

    
    while (h < t)
    {
        //out << h << endl;
        tx = qx[h]; ty = qy[h]; ts = qs[h]; td = qd[h++];
        //out << tx << " " << ty << " " << ts << " " << td << endl;
        switch (td) {
            case 0:
                if (m[tx][ty] == 2)
                    return ts;
                if (tx > 2 && m[tx-1][ty] && m[tx-2][ty] && !v[tx-2][ty][2]) {
                    qx[t] = tx - 2;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 2;
                    v[tx-2][ty][2] = true;
                }
                if ((tx + 3 < r) && m[tx+1][ty] && m[tx+2][ty] && !v[tx+1][ty][2]) {
                    qx[t] = tx + 1;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 2;
                    v[tx+1][ty][2] = true;
                }
                //out << ty << " " << (int)m[tx][ty-1] << " " << (int)m[tx][ty-2] << " " << v[tx][ty-2][1] << endl;
                if (ty > 2 && m[tx][ty-1] && m[tx][ty-2] && !v[tx][ty-2][1]) {
                    qx[t] = tx;
                    qy[t] = ty - 2;
                    qs[t] = ts + 1;
                    qd[t++] = 1;
                    v[tx][ty-2][1] = true;
                }
                if ((ty + 3 < c) && m[tx][ty+1] && m[tx][ty+2] && !v[tx][ty+1][1]) {
                    qx[t] = tx;
                    qy[t] = ty + 1;
                    qs[t] = ts + 1;
                    qd[t++] = 1;
                    v[tx][ty+1][1] = true;
                }
                break;
            case 1:
                if (tx > 1 && m[tx-1][ty] && m[tx-1][ty+1] && !v[tx-1][ty][1]) {
                    qx[t] = tx - 1;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 1;
                    v[tx-1][ty][1] = true;
                }
                if ((tx + 2 < r) && m[tx+1][ty] && m[tx+1][ty+1] && !v[tx+1][ty][1]) {
                    qx[t] = tx + 1;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 1;
                    v[tx+1][ty][1] = true;
                }
                if (ty > 1 && (m[tx][ty-1] > 0) && !v[tx][ty-1][0]) {
                    qx[t] = tx;
                    qy[t] = ty - 1;
                    qs[t] = ts + 1;
                    qd[t++] = 0;
                    v[tx][ty-1][0] = true;

                }
                if ((ty + 3 < c) && (m[tx][ty+2] > 0) && !v[tx][ty+2][0]) {
                    qx[t] = tx;
                    qy[t] = ty + 2;
                    qs[t] = ts + 1;
                    qd[t++] = 0;
                    v[tx][ty+2][0] = true;;
                }
                break;
            case 2:
                if (ty > 1 && m[tx][ty-1] && m[tx+1][ty-1] && !v[tx][ty-1][2]) {
                    qx[t] = tx;
                    qy[t] = ty - 1;
                    qs[t] = ts + 1;
                    qd[t++] = 2;
                    v[tx][ty-1][2] = true;

                }
                if ((ty + 2 < c) && m[tx][ty+1] && m[tx+1][ty+1] && !v[tx][ty+1][2]) {
                    qx[t] = tx;
                    qy[t] = ty + 1;
                    qs[t] = ts + 1;
                    qd[t++] = 2;
                    v[tx][ty+1][2] = true;
                }
                if (tx > 1 && (m[tx-1][ty] > 0) && !v[tx-1][ty][0]) {
                    qx[t] = tx - 1;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 0;
                    v[tx-1][ty][0] = true;
                }
                if ((tx + 3 < r) && (m[tx+2][ty] > 0) && !v[tx+2][ty][0]) {
                    qx[t] = tx + 2;
                    qy[t] = ty;
                    qs[t] = ts + 1;
                    qd[t++] = 0;
                    v[tx+2][ty][0] = true;
                }
                break;
        }
    }

    return -1;
}

int main()
{
    int res;

    while (input())
    {
        //output();
        res = bfs();
        if (res == -1)
            puts("Impossible");
        else
            printf("%d\n", res);
    }

    return 0;
}
