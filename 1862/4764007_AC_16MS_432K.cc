#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
  int n,arr[101];
  double res;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr,arr+n);
  res = arr[n-1];
  for(int i = n-2; i >= 0; i--)
    res = 2*sqrt(res*arr[i]);
  printf("%.3f\n",res);
  return 0;
}
