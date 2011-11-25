#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
  bool v[5010],flag1,flag2;
  int n,tmp;
  while(cin>>n&&n)
  {
    while(cin >> tmp&& tmp)
    {
      bool res(true);
      memset(v,false,sizeof(v));
      v[tmp] = true;
      for(int i = 1; i < n; i++){
        cin >> tmp;
        v[tmp] = true;
        flag1 = flag2 = false;
        for(int i = tmp+1; i<=n; i++)
          if(v[i])
            flag1 = true;
          else
            flag2 = true;
        if(flag1&&flag2)
          res = false;
      }
      cout << (res?"Yes":"No") << endl;
    }
    cout << endl;
  }
  return 0;
}