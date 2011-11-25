#include<iostream>
using namespace std;
#define ull unsigned long long
ull gcd(ull x,ull y)
{
  if(!x || !y)
    return 1;
  if(x%y)
    return (y,x%y);
  return y;
}

ull C(ull x,ull y)
{
  if(x == 0 || x == y || y == 0)
    return 1;
  ull res(1),res1(1),_y(x+1),_tmp;
  if(x > y/2)
    x = y - x;
  while(_y<=y||x>0){
    if(y <= y)
      res *= _y++;
    if(x > 0)
      res1 *= x--;
    }
  res /= gcd(res,res1);
  return res;
}
int main()
{
  ull m,n;
  while(cin>>m>>n&&(m||n))
  {
    cout << C(m,n+m) << endl;
  }
  return 0;
}
