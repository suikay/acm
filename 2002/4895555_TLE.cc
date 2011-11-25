#include<memory.h>
#include<algorithm>
#include<stdio.h>
//#include<stdlib.h>
#define MAX 1000
#define INF 100000
#define P  1584797
#define abs(x) (_x=x,_x=(_x>0)?_x:-_x)
int x[MAX],y[MAX];
struct Hash{
	bool v;
	double k;
	int len;
};
Hash h[P];
//int head[P];
int n;
int main()
{
  int midx,midy,xx,yy,tmp,ptr,res,len;
  int xtmp,ytmp;
  double kk,_x;
while(true){
  scanf("%d",&n);
  ptr = 1;
  res = 0;
  if(0 == n)
    return 0;
  //memset(head,0,sizeof(head));
  memset(h,0,sizeof(h));
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
      tmp = (midx*1997 + midy)%P;
	  while(tmp < 0)
		  tmp += P;
      //zz = head[tmp];
	  if(yy == 0)
		  kk = -INF;
	  else
		  kk = 1.0 * xx / yy;
	  while(h[tmp].v)
		  if(len == h[tmp].len && abs(kk + h[tmp].k) < 10e-5){
			  res++;
			  break;
			}
			else
			{
			  tmp++;
			  if(tmp == P)
				  tmp = 0;
			}
      if(h[tmp].v == false)
      {
        h[tmp].len = len;
		if(xx == 0)
			h[tmp].k = INF;
		else
			h[tmp].k = 1.0*yy/xx;
		h[tmp].v = true;
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
