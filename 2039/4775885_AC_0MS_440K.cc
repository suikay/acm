#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
  int n,sz,j,k;
  string ori,ey;
  while(cin >> n && n){
    cin >> ey;
    ori.resize(0);
    sz = ey.size();
    for(int i = n; i < sz; i+=2*n){
      if(i + n >= sz)
        reverse(ey.begin()+i,ey.end());
      else
        reverse(ey.begin()+i,ey.begin()+i+n);
    }
    for(int i = 0; i < min(n,sz); i++){
      j = i;
      while(j < sz){
        ori += ey[j];
        j += n;
      }
    }
    cout << ori << endl;
  }
  return 0;
}