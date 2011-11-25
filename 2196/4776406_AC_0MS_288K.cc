#include<stdio.h>
bool f(int x,int y)
{
  int p1(0),p2(0),x2(x);
  while(x){
    p1 += x % 10;
    x /= 10;
  }
  while(x2){
    p2 += x2 % y;
    x2 /= y;
  }
  return p1==p2;
}
int main()
{
  for(int i = 2992; i < 10000; i++)
    if(f(i,12)&&f(i,16))
      printf("%d\n",i);
  return 0;
}
