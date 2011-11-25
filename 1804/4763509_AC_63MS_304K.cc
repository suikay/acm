#include<stdio.h>
int main()
{
  int arr[1010];
  int n,res,t,tmp;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    res = 0;
    scanf("%d",&t);
    for(int j = 0; j < t; j++){
      scanf("%d",&tmp);
      for(int k = 0; k < j; k++)
        if(arr[k] > tmp)
          res++;
      arr[j] = tmp;
    }
    printf("Scenario #%d:\n",i);
    printf("%d\n\n",res);
  }
  return 0;
}
