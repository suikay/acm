#include<memory.h>
#include<algorithm>
#include<stdio.h>
#define MAX 1000
#define P 3500251
#define abs(x) (_x=x,_x=(_x>0)?_x:-_x)
int x[MAX],y[MAX];
bool hv[P];
int hyy[P];
int hxx[P];
int hlen[P];
int n;
int main()
{
  int midx,midy,xx,yy,tmp,ptr,res,len;
  int xtmp,ytmp;
while(true){
  scanf("%d",&n);
  ptr = 1;
  res = 0;
  if(0 == n)
    return 0;
  memset(hv,false,sizeof(hv));
  for(int i = 0;i < n; i++)
  {
    scanf("%d%d",&xtmp,&ytmp);
    for(int j = 0; j < i; j++)
    {
      midx = xtmp + x[j];
      midy = ytmp + y[j];
      xx = xtmp - x[j];
      yy = ytmp - y[j];
      len = xx*xx + yy*yy;
      tmp = (midx*1997 + midy*19 + len)%P;
	  while(tmp < 0)
		  tmp += P;
	  while(hv[tmp])
        if(len == hlen[tmp] && (xx*hxx[tmp]+yy*hyy[tmp])==0){
          res++;
          break;
        }
        else
		{
          tmp++;
		  if(tmp == P)
			  tmp = 0;
		}
      if(hv[tmp] == false)
      {
        hlen[tmp] = len;
        hxx[tmp] = xx;
        hyy[tmp] = yy;
		hv[tmp] = true;
      }
    }
    x[i] = xtmp;
    y[i] = ytmp;
}
    printf("%d\n",res);
}
  return 0;
}

