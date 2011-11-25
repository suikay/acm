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
//Hash h[P];
//int head[P];
int n;
int main()
{
  int midx,midy,xx,yy,zz,tmp,ptr,res,len,_x;
  int xtmp,ytmp;
  //Hash *now;
while(true){
  scanf("%d",&n);
  ptr = 1;
  res = 0;
  if(0 == n)
    return 0;
  //memset(head,0,sizeof(head));
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
      tmp = (midx*1997 + midy*19)%P;
	  while(tmp < 0)
		  tmp += P;
      //zz = head[tmp];
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
        //h[tmp].next = head[tmp];
        //head[tmp] = ptr++;
      }
    }
    x[i] = xtmp;
    y[i] = ytmp;
}
    printf("%d\n",res);
}
  return 0;
}

