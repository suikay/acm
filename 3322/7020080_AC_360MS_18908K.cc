#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int N = 500;
char m[N+1][N+1];
char v[N+1][N+1][3];
int r, c;
int orix, oriy, orid;
int desx, desy;

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

    memset(v, -1, sizeof(v));
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
            else if (ch == 'O') {
                desx = i;
                desy = j;
                m[i][j] = 2;
            }
            else
                m[i][j] = 1;
        }
        ch = getchar();
    }
    return true;
}


int qx[2][N*N*3], qy[2][N*N*3], qd[2][N*N*3], qs[2][N*N*3], hh[2], tt[2];
int bfs()
{
    int tx, ty, ts, td;
    int sf, cnt, step, h, t;

    h = t = 0;
    qx[0][0] = orix;
    qy[0][0] = oriy;
    qs[0][0] = 0;
    qd[0][0] = orid;
    v[orix][oriy][orid] = 0;

    qx[1][0] = desx;
    qy[1][0] = desy;
    qs[1][0] = 0;
    qd[1][0] = 0;
    v[desx][desy][0] = 1;

    hh[0] = 0; tt[0] = 1;
    hh[1] = 0; tt[1] = 1;
    
    cnt = 1;
    while (hh[0] < tt[0] || hh[1] < tt[1])
    {
        sf = (cnt - 1) % 2;
        step = (cnt - 1) / 2;
        h = hh[sf]; t = tt[sf];

        while (h < t && qs[sf][h] <= step)
        {
            tx = qx[sf][h]; ty = qy[sf][h]; ts = qs[sf][h]; td = qd[sf][h++];
            //cout << tx << " " << ty << " " << ts << " " << td << endl;
            //cout << (int)v[desx][desy][0] << endl;
            switch (td) {
                case 0:
                    if (tx > 2 && m[tx-1][ty] && m[tx-2][ty])
                        if (v[tx-2][ty][2] == -1) {
                            qx[sf][t] = tx - 2;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 2;
                            v[tx-2][ty][2] = sf;
                        } else if (v[tx-2][ty][2] != sf) {
                            return cnt;
                        }
                    if ((tx + 3 < r) && m[tx+1][ty] && m[tx+2][ty])
                        if (v[tx+1][ty][2] == -1) {
                            qx[sf][t] = tx + 1;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 2;
                            v[tx+1][ty][2] = sf;
                        } else if (v[tx+1][ty][2] != sf) {
                            return cnt;
                        }
                    if (ty > 2 && m[tx][ty-1] && m[tx][ty-2])
                        if (v[tx][ty-2][1] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty - 2;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 1;
                            v[tx][ty-2][1] = sf;
                        } else if (v[tx][ty-2][1] != sf) {
                            return cnt;
                        }
                    if ((ty + 3 < c) && m[tx][ty+1] && m[tx][ty+2])
                        if (v[tx][ty+1][1] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty + 1;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 1;
                            v[tx][ty+1][1] = sf;
                        } else if (v[tx][ty+1][1] != sf) {
                            return cnt;
                        }
                    break;
                case 1:
                    if (tx > 1 && m[tx-1][ty] && m[tx-1][ty+1])
                        if (v[tx-1][ty][1] == -1) {
                            qx[sf][t] = tx - 1;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 1;
                            v[tx-1][ty][1] = sf;
                        } else if (v[tx-1][ty][1] != sf) {
                            return cnt;
                        }
                    if ((tx + 2 < r) && m[tx+1][ty] && m[tx+1][ty+1])
                        if (v[tx+1][ty][1] == -1) {
                            qx[sf][t] = tx + 1;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 1;
                            v[tx+1][ty][1] = sf;
                        } else if (v[tx+1][ty][1] != sf) {
                            return cnt;
                        }
                    if (ty > 1 && (m[tx][ty-1] > 0))
                        if (v[tx][ty-1][0] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty - 1;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 0;
                            v[tx][ty-1][0] = sf;
                        } else if (v[tx][ty-1][0] != sf) {
                            return cnt;
                        }
                    if ((ty + 3 < c) && (m[tx][ty+2] > 0))
                        if (v[tx][ty+2][0] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty + 2;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 0;
                            v[tx][ty+2][0] = sf;;
                        } else if (v[tx][ty+2][0] != sf) {
                            return cnt;
                        }
                    break;
                case 2:
                    if (ty > 1 && m[tx][ty-1] && m[tx+1][ty-1]) 
                        if (v[tx][ty-1][2] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty - 1;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 2;
                            v[tx][ty-1][2] = sf;
                        } else if (v[tx][ty-1][2] != sf) {
                            return cnt;
                        }
                    if ((ty + 2 < c) && m[tx][ty+1] && m[tx+1][ty+1])
                        if (v[tx][ty+1][2] == -1) {
                            qx[sf][t] = tx;
                            qy[sf][t] = ty + 1;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 2;
                            v[tx][ty+1][2] = sf;
                        } else if (v[tx][ty+1][2] != sf) {
                            return cnt;
                        }
                    if (tx > 1 && (m[tx-1][ty] > 0))
                        if (v[tx-1][ty][0] == -1) {
                            qx[sf][t] = tx - 1;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 0;
                            v[tx-1][ty][0] = sf;
                        } else if (v[tx-1][ty][0] != sf) {
                            return cnt;
                        }
                    if ((tx + 3 < r) && (m[tx+2][ty] > 0))
                        if (v[tx+2][ty][0] == -1) {
                            qx[sf][t] = tx + 2;
                            qy[sf][t] = ty;
                            qs[sf][t] = ts + 1;
                            qd[sf][t++] = 0;
                            v[tx+2][ty][0] = sf;
                        } else if (v[tx+2][ty][0] != sf) {
                            return cnt;
                        }
                    break;
            }

        }
        hh[sf] = h;
        tt[sf] = t;
        cnt++;
    }


    return -1;
}

int main()
{
    int res;

    while (input())
    {
        res = bfs();
        if (res == -1)
            puts("Impossible");
        else
            printf("%d\n", res);
    }

    return 0;
}