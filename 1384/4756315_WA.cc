#include<memory.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Coin
{
  int p,w;
  double ave;
  bool operator()(Coin a,Coin b)
  {     return a.ave < b.ave;   }
};
Coin coin[510];

int main()
{
  int T,E,F,N;
  int money[10010];
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&E,&F);
    F -= E;
    memset(money,-1,sizeof(money));
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
      scanf("%d%d",&(coin[i].p),&(coin[i].w));
      coin[i].ave = 1.0*coin[i].p/coin[i].w;
    }
    sort(coin,coin+N,Coin());
    int p,w;
    money[0] = 0;
    for(int i = 0; i < N; i++)
    {
      p = coin[i].p;
      w = coin[i].w;
      for(int j = 0; j + w <= F; j++)
        if(money[j] >= 0 && money[j+w]<0)
          money[j+w] = money[j] + p;
      if(money[F] >= 0){
        printf("The minimum amount of money in the piggy-bank is %d.\n",money[F]);
        break;
      }
    }
    if(money[F] < 0)
      printf("This is impossible.\n");
  }
  return 0;
}