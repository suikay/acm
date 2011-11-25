#include<stdio.h>
int main()
{
  int arr[10000],res[10000];
  int n,j,k,l;
  bool v[10000]={false};
  scanf("%d",&n);
  arr[0] = 0;
  for(int i = 1; i < n; i++)
    scanf("%d",&arr[i]);
  for(int i = n-1; i >= 0; i--)
  {
    j = arr[i];
    k = 1;
    for(l = 1;j >= 0; l++)
      if(!v[l])
        j--;
    v[--l] = true;
    res[i] = l;
//    printf("%d\n",l);
  }

  for(int i = 0; i < n; i++)
    printf("%d\n",res[i]);
  return 0;
}
