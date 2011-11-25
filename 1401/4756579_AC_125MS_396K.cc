#include<iostream>
using namespace std;
int main()
{
  int n,tmp;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    int res(0);
    scanf("%d",&tmp);
    while(tmp){
      res += tmp/5;
      tmp /= 5;
    }
    cout << res << endl;
  }
  return 0;
}
