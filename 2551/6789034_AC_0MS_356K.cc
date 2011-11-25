#include <stdio.h>
int main(int argc, const char *argv[])
{
    int ori,digit,k,m;
    while(scanf("%d",&m) == 1)
    {
        digit = 1;
        ori = 1;
        while(ori <= m) {
            ori = ori*10 + 1;
            digit++;
        }
        k = ori % m;
        while(k) 
        {
            k = (10*k + 1) % m;
            digit++;
        }
        printf("%d\n",digit);
    }

    return 0;
}
