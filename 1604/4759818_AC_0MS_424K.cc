#include<iostream>
using namespace std;
int main()
{
  long long n,res;
  while(cin >> n)
  {
    res = 1;
    for(long long i = 2; i <= n; i++){
      res *= i;
      while(res%10 == 0)
        res /= 10;
      res %= 1000000000;
    }
    printf("%5d",n);
    printf(" -> %d\n",res % 10);
  }
  return 0;
}
