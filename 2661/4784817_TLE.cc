#include<math.h>
#include<stdio.h>
#define pi 3.14159265
#define e 2.71828183 
int main()
{
  int y,last(0);
  double m;
  while(scanf("%d",&y)&&y)
  {
    m = pow(2.0,(y-1940)/10)*log(2.0);
    for(int n = 1; true; n++)
      if(n*log(1.0*n/e)+log(sqrt(2*pi*n)) > m)
        break;
      else
        last = n;
    printf("%d\n",last);
  }
  return 0;

}