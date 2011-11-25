#include<iostream>
using namespace std;
int main()
{
  int res,a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {
    if(!a&&!b&&!c&&!d)
      break;
    res = 1080;
    res += (40+a-b)%40*9;
    //res += min((40+a-b)%40,(40+b-a)%40)*9;
    //cout << res << endl;
    res += (40+c-b)%40*9;
    //cout << res << endl;
    res += (40+c-d)%40*9;
    cout << res << endl;
  }
  return 0;
}