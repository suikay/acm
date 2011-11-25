#include<iostream>
using namespace std;
int main()
{
  int n;
  while(cin >> n){
    for(int i = 1; i < n; i++)
      if(i*(i+1)/2 >= n){
        if(i%2){
          int last = n - (i-1)*i/2;
          cout<< "TERM "<< n << " IS " <<(i+1-last)<<'/'<< last << endl;
          break;
        }
        else{
          int last = n - (i-1)*i/2;
          cout << "TERM "<< n << " IS "<< last << '/' << (i+1-last) << endl;
          break;
        }
      }
  }
  return 0;
}
