#include<math.h>
#include<iostream>
using namespace std;
#define pi 3.14159265
#define e 2.71828183 
int main()
{
  int y,n,m,last;
  while(scanf("%d",&y)&&y)
  {
    m = pow(2,(y-1940)/10);
    for(int n = 1; true; n++)
      if((int)(0.9999+n*(log(1.0*n/e)/log(2))+log(sqrt(2*pi*n))/log(2)) > m)
        break;
      else
        last = n;
    printf("%d\n",last);
  }
  return 0;

}
