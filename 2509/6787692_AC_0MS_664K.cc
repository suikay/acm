#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    long long k,tmp,m,n,res,last;
    while(scanf("%lld%lld",&m,&n) == 2)
    {
        res = m;
        k = n;
        while(true)
        {
            tmp = m / n;
            last = m % n;
            if(!tmp) break;
            res += tmp;
            m = tmp + last;
            k *= n;
        }
        printf("%lld\n",res);
    }
    return 0;
}
