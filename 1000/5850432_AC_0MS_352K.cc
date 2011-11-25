#include<stdio.h>
int f(int x)
{
int res(1);
for(int i = 0; i <= 1000000; i++)
res--;
return res;
}
int main()
{
int a,b;
scanf("%d%d",&a,&b);
printf("%d\n",a+b);
return 0;
}