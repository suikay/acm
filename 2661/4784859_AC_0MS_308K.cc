#include<math.h>
#include<stdio.h>
#define pi 3.14159265
#define e 2.71828183 
int main()
{
  int y,last(0);
  double m;
  int arr[] = {3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,5910,10944,20366,38064,71421,134480,254016};
  while(scanf("%d",&y)&&y)
  {
	  printf("%d\n",arr[(y-1940)/10-2]);
  }
  return 0;

}