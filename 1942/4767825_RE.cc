#include<iostream>
using namespace std;
long long C(long long x,long long y)
{
  if(x == 0 )
    return 1;
  if(y == 0)
    return 1;
  return C(x-1,y)+C(x,y-1);
}
int main()
{
  long long m,n;
  while(cin>>m>>n&&(m||n))
  {
    cout << C(m,n) << endl;
  }
  return 0;
}
