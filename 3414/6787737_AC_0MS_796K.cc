#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a,b,c,d;
int deep[110][110];
int path[110][110];
int type[110][110];
int res;
int min(int x,int y) {
    if(x < y)
        return x;
    return y;
}

int queue[1<<13],top,tail;
bool bfs()
{
    int x,y,de;
    memset(deep,0x7f,sizeof(deep));
    deep[0][0] = 0;
    top = tail = 0;
    queue[tail++] = 0;
    while(top < tail)
    {
        x = queue[top] & 127;
        y = queue[top] >> 7;
        de = deep[x][y]+1;
        if(x == d || y == d) {
            res = (y << 7) + x ;
            return true;
        }
        if(x < a && deep[a][y] > de) {
            type[a][y] = 0;
            deep[a][y] = de;
            path[a][y] = queue[top];
            queue[tail++] = (y << 7) + a;
        }
        if(y < b && deep[x][b] > de) {
            type[x][b] = 1;
            deep[x][b] = de;
            path[x][b] = queue[top];
            queue[tail++] = (b << 7) + x;
        }
        c = min(y,a-x);
        if(c && deep[x+c][y-c] > de) {
            type[x+c][y-c] = 2;
            deep[x+c][y-c] = de;
            path[x+c][y-c] = queue[top];
            queue[tail++] = ((y-c) << 7) + x+c;
            // << "PATH " << x+c << " " << y-c << " " << queue[top] << endl;
        }
        c = min(x,b-y);
        if(c && deep[x-c][y+c] > de) {
            type[x-c][y+c] = 3;
            deep[x-c][y+c] = de;
            path[x-c][y+c] = queue[top];
            queue[tail++] = ((y+c) << 7) + x-c;
        }
        if(x && deep[0][y] > de) {
            type[0][y] = 4;
            deep[0][y] = de;
            path[0][y] = queue[top];
            queue[tail++] = y<<7;
        }
        if(y && deep[x][0] > de) {
            type[x][0] = 5;
            deep[x][0] = de;
            path[x][0] = queue[top];
            queue[tail++] = x;
        }
        top++;
    }
    return false;

}
void output()
{
    int x,y,tmp;
    x = res & 127;
    y = res >> 7;
    int queue[10000],top;
    top = 0;
    while(deep[x][y])
    {
        queue[top++] = type[x][y];
        tmp = path[x][y];
        x = tmp & 127;
        y = tmp >> 7;
    }
    //cout << " TOP " << top << endl;
   while(top--) 
    {
            //x = queue[top] & 127;
            //y = queue[top] >> 7;
            switch(queue[top]/*type[x][y]*/) {
                case 0: puts("FILL(1)"); break;
                case 1: puts("FILL(2)"); break;
                case 2: puts("POUR(2,1)"); break;
                case 3: puts("POUR(1,2)"); break;
                case 4: puts("DROP(1)");   break;
                case 5: puts("DROP(2)");   break;
            }
     }

}
int main(int argc, const char *argv[])
{
    scanf("%d%d%d",&a,&b,&d);
    if(bfs()) {
        // << "RES " << res << endl;
        printf("%d\n",deep[res&127][res>>7]);
        output();
    }
    else
        puts("impossible");
    
    return 0;
}
