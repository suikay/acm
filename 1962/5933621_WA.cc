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
const int N = 21000;
int p[N],len[N];
inline int dfs(int x)
{
    if(p[x] == x) {
        //father = x;
        return 0;
    }
    len[x] += dfs(p[x]);
    p[x] = p[p[x]];
    return len[x] %= 1000;
}
inline void init()
{
    for(int i = 0; i < N; i++)
        p[i] = i;
    memset(len,0,sizeof(len));
}
int main() {
    int t,n;
    int tmp,t1,t2;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        while(true)
        {
            do {
                ch = getchar();
            }while(ch == ' ' || ch == '\n');
            if(ch == 'O') break;
            if(ch == 'E') {
                scanf("%d",&tmp);
                printf("%d\n",dfs(tmp));
            } else {
                scanf("%d%d",&t1,&t2);
                p[t1] = t2;
                len[t1] = labs(t1-t2)%1000;
            }
        }
    }

    return 0;
}

