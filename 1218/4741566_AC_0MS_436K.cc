#include<memory.h>
#include<iostream>
using namespace std;
bool gone[101];
int main()
{
  int n,tmp;
  cin >> n;
  while(n--)
  {
    cin >> tmp;
    memset(gone,false,sizeof(gone));
    for(int i = 1; i <= tmp; i++)
      for(int j = i; j <= tmp; j+=i)
        gone[j] = !gone[j];
    int res(0);
    for(int i = 1; i <= tmp; i++)
      if(gone[i])
        res++;
    cout << res << endl;
  }
  return 0;
}
