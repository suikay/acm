#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
bool v[1010];
int main()
{
  int m,n,arr[51];
  int time(1);
  while(cin>>m>>n&&m)
  {
    int res(0);
    memset(v,false,sizeof(v));
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      v[arr[i]] = true;
    }
    sort(arr,arr+n);
    for(int i = n-1;i >= 0;i--)
    {
      bool flag = false;
      for(int j = arr[i]+1; j <= m*n; j++)
        if(!v[j]){
          v[j] = true;
          flag = true;
          break;
        }
      if(!flag)
        res++;
    }
    cout << "Case "<< time++ << ": " << res << endl;
  }
  return 0;
}
