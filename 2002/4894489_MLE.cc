#include<memory.h>
#include<algorithm>
#include<stdio.h>
#define MAX 1000
#define P 12000000
#define abs(x) (_x=x,_x=(_x>0)?_x:-_x)
int x[MAX],y[MAX];
struct Hash{
	bool v;
	int yy;
	int xx;
	int len;
  //int next;
};
Hash h[P];
//int head[P];
int n;
int main()
{
  int midx,midy,xx,yy,zz,tmp,ptr,res,len,_x;
  int xtmp,ytmp;
  Hash *now;
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
      tmp = abs(midx*9649 + midy*19)%P;
      //zz = head[tmp];
	  while(h[tmp].v)
        if(len == h[tmp].len && (xx*h[tmp].xx+yy*h[tmp].yy)==0){
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
        h[tmp].xx = xx;
        h[tmp].yy = yy;
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
