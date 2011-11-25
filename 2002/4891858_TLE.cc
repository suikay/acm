#include<memory.h>
#include<algorithm>
#include<stdio.h>
#define MAX 1000
#define P 11385527
int x[MAX],y[MAX];
struct Hash{
  int yy;
  int xx;
  int len;
  int next;
};
Hash h[MAX*MAX];
int head[P];
int n;
int main()
{
  int midx,midy,xx,yy,zz,tmp,ptr,res,len;
  Hash *now;
while(true){
  scanf("%d",&n);
  ptr = 1;
  res = 0;
  if(0 == n)
    return 0;
  memset(head,0,sizeof(head));
  memset(h,0,sizeof(h));
  for(int i = 0;i < n; i++)
    scanf("%d%d",&(x[i]),&(y[i]));
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
      midx = x[i] + x[j];
      midy = y[i] + y[j];
      xx = x[i] - x[j];
      yy = y[i] - y[j];
      len = xx*xx + yy*yy;
      tmp = abs(midx + midy*3547)%P;
      zz = head[tmp];
      while(zz)
      {
        now = &h[zz];
        if((xx*now->xx+yy*now->yy)==0 && ((len - now->len)==0)){
          res++;
          break;
        }
        else
          zz = now->next;
      }
      if(!zz)
      {
        now = &h[ptr];
        now->len = len;
        now->xx = xx;
        now->yy = yy;
        now->next = head[tmp];
        head[tmp] = ptr++;
      }
    }
    printf("%d\n",res);
}
  return 0;
}