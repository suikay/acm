#include<algorithm>
using namespace std;
#include<stdio.h>
int main()
{
  int t,n,max;
  int arr[1100];
  scanf("%d",&t);
  while(t--)
  {
    max = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
      scanf("%d",&arr[i]);
    sort(arr,arr+n);
    for(int i = 0; i < n; i++)
      if(arr[i]*(n - i) > max)
        max = arr[i]*(n-i);
    printf("%d\n",max);
  }
  return 0;
}
