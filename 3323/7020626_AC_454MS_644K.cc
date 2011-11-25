#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//int abs(int x)
//{
    //if (x >= 0)
        //return x;
    //return -x;
//}
//int min(int x, int y)
//{
    //if (x > y)
        //return y;
    //else
        //return x;
//}
//void swap(int &x, int& y)
//{
    //int tmp;
    //tmp = x;
    //x = y;
    //y = tmp;
//}

int m[][7] = {
    {0,3,4,2,5,6,4},
    {3,6,6,3,6,7,5},
    {4,6,6,4,6,7,6},
    {2,3,4,4,5,6,6},
    {5,6,6,5,6,7,7},
    {6,7,7,6,7,8,8},
    {4,5,6,6,7,8,8}};

int cal(int x, int y)
{
    int xx,px,yy,py,res;
    x = abs(x);
    y = abs(y);
    if (x > y)
        swap(x, y);
    //cout << x << " " << y << endl;
    yy = y % 3;
    py = y / 3 * 2;
    xx = x % 3;
    px = x / 3 * 2;
    res = px+py+m[xx][yy];
    if (y >= 3) {
        res = min(res, px+py-2+m[xx][yy+3]);
        if (x >= 3) {
            res = min(res, min(px+py-2+m[xx+3][yy], px+py-4+m[xx+3][yy+3]));
        }
    } else
        return m[x][y];
    return res;
}
int main()
{
    char ch;
    int x, y, res;

    while(scanf("%c%d%d\n", &ch, &x, &y) == 3)
    {
        res = 0x7fffffff;
        switch (ch) {
            case 'U':
                printf("%d\n", cal(x, y));
                break;
            case 'H':
                for (int i = -2; i <= 2; i++) {
                    res = min(res, cal(x+i, y-1)+abs(i)+1);
                    res = min(res, cal(x+i, y+2)+abs(i)+1);
                }
                printf("%d\n", res);
                break;
            case 'V':
                for (int i = -2; i <= 2; i++) {
                    res = min(res, cal(x-1, y+i)+abs(i)+1);
                    res = min(res, cal(x+2, y+i)+abs(i)+1);
                }
                printf("%d\n", res);

        }
    }

    return 0;
}
