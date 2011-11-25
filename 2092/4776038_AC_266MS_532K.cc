#include<memory.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Player{
  int ID;
  int total;
  bool operator()(Player a,Player b)
  {
    if(a.total != b.total)
      return a.total > b.total;
    else
      return a.ID < b.ID;
  }
};
int main()
{
  int n,m;
  Player p[10010];
  while(cin>>n>>m&&n)
  {
    int tmp;
    memset(p,0,sizeof(p));
    for(int i = 0; i < m*n; i++){
      scanf("%d",&tmp);
      p[tmp].total++;
      p[tmp].ID = tmp;
    }
    sort(p,p+10010,Player());
    int max = p[1].total;
    for(int i = 1; p[i].total>=max; i++)
      cout << p[i].ID << " ";
    cout << endl;
  }
  return 0;
}
