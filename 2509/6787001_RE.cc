#include <stdio.h>
int main()
{
int k,tmp,m,n,res,last;
while(scanf("%d%d",&m,&n) == 2)
{
res = m;
k = n;
while(true)
{
tmp = m / k;
last = m % k;
if(!tmp) break;
res += tmp;
m += tmp;
k *= n;
}
printf("%d\n",res);
}
return 0;
}