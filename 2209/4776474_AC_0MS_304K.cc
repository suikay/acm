#include<stdio.h>
int main()
{
  int son,f,tmp,res(0);
  scanf("%d%d",&son,&f);
  if(f==1)
    for(int i = 0; i < son; i++){
      scanf("%d",&tmp);
      if(tmp > 0)
        res += tmp;
    }
    else
      if(f == 2){
        for(int i = 0; i < son; i++){
          scanf("%d",&tmp);
          res += tmp*tmp;
        }
      }
      else
      {
        for(int i = 0; i < son; i++){
          scanf("%d",&tmp);
          if(tmp > 0)
            res += tmp*tmp*tmp;
        }
      }
    printf("%d\n",res);
    return 0;
  }