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
bool v[21];
bool take(int x)
{
    bool ori[21];
    memcpy(ori,v,sizeof(v));
    for(int i = 2; i < 20; i++) {
        if(v[i])
            for(int j = i+x; j < 21; j+=x)
                v[j] = true;
    }
    bool ok(false),win(false),lose(false);
    for(int k = 2; k < 21; k++)
        if(!v[k]) {
            ok = true;
            v[k] = true;
            if(take(k)==1) {
                memcpy(v,ori,sizeof(v));
                v[k] = false;
                return false;
            }
            v[k] = false;
            ok = true;
        }
    memcpy(v,ori,sizeof(v));
    return true;
}
int main() {
    int n,cnt(1),tmp;
    vector<int>res;
    while(scanf("%d",&n) && n)
    {
        res.resize(0);
        memset(v,true,sizeof(v));
        for(int i = 0; i < n; i++) {
            scanf("%d",&tmp);
            v[tmp] = false;
        }
        for(int i = 2; i < 21; i++)
            if(!v[i]) {  
                v[i] = true;
                if(take(i))
                    res.push_back(i);
                v[i] = false;
            }
        if(res.empty()) {
            printf("Test Case #%d\n",cnt++);
            printf("There's no winning move.\n\n");
            continue;
        }
        printf("Test Case #%d\nThe winning moves are:",cnt++);
        for(int i = 0; i < res.size(); i++)
            printf(" %d",res[i]);
        printf("\n\n");
    }

    return 0;
}


