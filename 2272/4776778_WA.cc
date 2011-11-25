#include<math.h>
#include<iostream>
using namespace std;
double kk(double x)
{
  if(x - (int)x < 10e-4)
    return ((int)x)*1.00000000;
  if((int)(x+1) - x < 10e-4)
    return ((int)(x+1))*1.0000000;
  return x;
}
int f(){
  double x,y,r;
  int res(0);
    for(int i = 0; i < 3; i++){
      cin >> x >> y;
      if(x == -100)
        return -1;
      r = kk(sqrt(x*x+y*y));
      if(r <= 3.0)
        res += 100;
      else
        if(r <= 6.0)
          res += 80;
        else
          if(r <= 9.0)
            res += 60;
          else
            if(r <= 12.0)
              res += 40;
            else
              if(r <= 15.0)
                res += 20;
    } 
    return res;
}
int main()
{
  double x,y,r;
  while(true)
  {
    int p1,p2;
    p1 = f();
    p2 = f();
    if(p1 == -1)
      break;
    if(p1 > p2)
      printf("SCORE: %d to %d, PLAYER 1 WINS.\n",p1,p2);
    else
      if(p1 < p2)
        printf("SCORE: %d to %d, PLAYER 2 WINS.\n",p1,p2);
      else
        printf("SCORE: %d to %d, TIE.\n",p1,p1);
  }
  return 0;
}
