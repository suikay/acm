#include<iostream>
using namespace std;
int main()
{
  int n,res(0),tmp;
  cin >> n;
  for(int i = 1;!res && i <= n; i++){
    tmp = i*(i+1)/2;
    if(tmp < n)
      continue;
    if(tmp==n||!((tmp-n)%2)){
      res = i;
      break;
    }
  }
  cout << res << endl;
  return 0;
}
