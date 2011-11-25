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
  sort(p,p + n,Point());
  return true;
}
int f()
{
  int midx,midy,xx,yy,zz,tmp,ptr,res;
  ptr = 1;
  res = 0;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
      midx = p[i].x + p[j].x;
      midy = p[i].y + p[j].y;
      xx = p[i].x - p[j].x;
      yy = p[i].y - p[j].y;
      tmp = abs(midx*midx*13 + midy*midy)%P;
      zz = head[tmp];
      while(zz)
        if(h[zz].Midx == midx && h[zz].Midy == midy && (xx*h[zz].xx+yy*h[zz].yy)==0){
          res++;
          break;
        }
        else
          zz = h[zz].next;
      if(!zz)
      {
        h[ptr].Midx = midx;
        h[ptr].Midy = midy;
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