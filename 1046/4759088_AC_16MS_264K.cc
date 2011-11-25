#include<stdio.h>
#define cal(a,b) (a-b)*(a-b)
int main()
{
  int a[16], b[16],c[16];
  int D,ta,tb,tc,oa,ob,oc,tmp;
  for(int i = 0; i < 16; i++)
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
  while(scanf("%d%d%d",&oa,&ob,&oc)&&oa>=0)
  {
    D = 3*255*255+1;
    for(int i = 0; i < 16; i++){
        tmp = cal(oa,a[i])+cal(ob,b[i])+cal(oc,c[i]);
      if(D > tmp){
        D = tmp;
        ta = a[i];
        tb = b[i];
        tc = c[i];
      }
    }
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n",oa,ob,oc,ta,tb,tc);
  }
  return 0;
}
