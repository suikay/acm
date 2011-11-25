#include<memory.h>
#include<algorithm>
#include<stdio.h>
#define MAX 1000
#define P 6429139
using namespace std;
struct Point{
  int x;
  int y;
  bool operator()(Point a,Point b)
  {
    return ((a.x < b.x) || (a.x == b.x && a.y == b.y));
  }
};
struct Hash{
  int Midy;
  int Midx;
  int yy;
  int xx;
  int len;
  int next;
};
Hash h[MAX*MAX];
int head[P];
int n;
Point p[MAX];
bool input()
{
  scanf("%d",&n);
  if(0 == n)
    return false;
  memset(p,0,sizeof(p));
  memset(head,0,sizeof(head));
  memset(h,0,sizeof(h));
  for(int i = 0;i < n; i++)
    scanf("%d%d",&p[i].x,&p[i].y);
  //sort(p,p + n,Point());
  return true;
}
int f()
{
  int midx,midy,xx,yy,zz,tmp,ptr,res,len;
  Hash *now;
  ptr = 1;
  res = 0;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
      midx = p[i].x + p[j].x;
      midy = p[i].y + p[j].y;
      xx = p[i].x - p[j].x;
      yy = p[i].y - p[j].y;
      len = xx*xx + yy*yy;
      tmp = abs(midx*13 + midy*7547)%P;
      zz = head[tmp];
      while(zz)
      {
        now = &h[zz];
        if((xx*now->xx+yy*now->yy)==0 && ((len - now->len)==0)){
          res++;
          break;
        }
        else
          zz = h[zz].next;
      }
      if(!zz)
      {
        h[ptr].len = len;
        h[ptr].xx = xx;
        h[ptr].yy = yy;
        h[ptr].next = head[tmp];
        head[tmp] = ptr++;
      }
    }
  return res;
}

int main()
{
  while(input())
  {
    printf("%d\n",f());
  }
  return 0;
}
