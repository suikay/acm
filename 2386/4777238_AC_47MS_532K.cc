#include<iostream>
using namespace std;
int main()
{
  char map[110][110];
  int n,m,res(0),xx,yy;
  int px[] = {-1,-1,-1,0,1,1,1,0},py[] = {1,0,-1,-1,-1,0,1,1};
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> map[i][j];
  int y[11000],x[11000],top(0);
  for(int i = 1; i <=n; i++)
    for(int j = 1; j <= m; j++)
      if(map[i][j] == 'W'){
        res++;
        map[i][j] = '.';
        x[top] = i;
        y[top] = j;
        top++;
        while(top){
          xx = x[--top];
          yy = y[top];
          for(int k = 0; k < 8; k++)
            if(map[xx+px[k]][yy+py[k]] == 'W'){
              x[top] = xx+px[k];
              y[top] = yy+py[k];
              map[x[top]][y[top]] = '.';
              top++;
            }
        }
      }
  cout << res << endl;
  return 0;
}
