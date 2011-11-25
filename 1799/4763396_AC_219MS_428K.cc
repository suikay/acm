#include<math.h>
#include<iostream>
#include<stdio.h>
#define pi 3.1415926
using namespace std;
int main()
{
  int time(1),t,n;
  double R;
  cin >> t;
  for(int i = 1; i <= t; i++){
    cin >> R >> n;
    printf("Scenario #%d:\n",i);
    double res = R/(1+1.0/cos(pi/2-pi/n));
    printf("%.3f\n\n",res);
  }
  return 0;
}
