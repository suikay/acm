#include<iostream>
using namespace std;
long long gcd(long long x,long long y)
{
  if(!x || !y)
    return 1;
  if(x%y)
    return (y,x%y);
  return y;
}

long long C(long long x,long long y)
{
  if(x == 0 )
    return 1;
  if(y == 0)
    return 1;
  int res(1),res1(1),_y(x+1),_tmp;
  if(x > y/2)
    x = y - x;
  while(_y<=y||x>0){
    if(y <= y)
      res *= _y++;
    if(x > 0)
      res1 *= x--;
    _tmp = gcd(res,res1);
    res/= _tmp;
    res1 /= _tmp;
  }
  return res;
}
int main()
{
  long long m,n;
  while(cin>>m>>n&&(m||n))
  {
    cout << C(m,n+m) << endl;
  }
  return 0;
}
