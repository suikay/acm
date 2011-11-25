#include <stdio.h>
#include <string.h>
char w[10010],t[1000100];
int p[10010];
void make()
{
    int j = -1;
    p[0] = -1;
    for(int i = 1; w[i]; i++)
    {
        while(j >= 0 && w[i] != w[j+1])
            j = p[j];
        if(w[i] == w[j+1])
            j++;
        p[i] = j;
    }
}
int compare()
{
    int res = 0;
    int j = -1;
    for(int i = 0; t[i]; i++)
    {
        while(j >= 0 && w[j+1] != t[i])
            j = p[j];
        if(w[j+1] == t[i])
            j++;
        if(!w[j+1]) {
            res++;
            j = p[j];
        }
    }

    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    gets(w);
    while(n--)
    {
        gets(w);
        gets(t);
        make();
        printf("%d\n",compare());   
    }

    return 0;
}