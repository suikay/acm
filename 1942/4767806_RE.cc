#include<iostream>
using namespace std;
unsigned int C(int x,int y)
{
  if(x == 0 )
    return 1;
  if(y == 0)
    return 1;
  return C(x-1,y)+C(x,y-1);
}
int main()
{
  unsigned int m,n;
  while(cin>>m>>n&&(m||n))
  {
    cout << C(m,n) << endl;
  }
  return 0;
}
