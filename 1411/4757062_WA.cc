#include<math.h>
#include<stdio.h>
#include<memory.h>
int prime[10000],pN,locat[100010];
bool num[100010]={false};
void make_prime()
{
  pN = 0;
  for(int i = 2; i <= 100000; i++){
    if(!num[i]){
      for(int j = 2*i; j <= 100000; j+=i)
        num[j] = true;
      locat[i] = pN;
      prime[pN++] = i;
    }
    else
      locat[i] = pN;
  }
}

int main()
{
  make_prime();
  int m,a,b;
  bool flag;
  while(scanf("%d%d%d",&m,&a,&b)&&m)
  {
    flag = true;
    int start,end;
    for(int i = m; flag && i >= 0; i--) {
      start = sqrt(1.0*i*a/b);
//      if(!num[start])
  //      start = locat[start]+1;
  //    else
        start = locat[start];
      end = sqrt(1.0*i);
      if(num[end])
        end = locat[end]-1;
      else
        end = locat[end];
      for(int j = start;flag && j <= end; j++)
        if(!(i%prime[j]) && !(num[i/prime[j]]))
        {
          printf("%d %d\n",prime[j],i/prime[j]);
          flag = false;
        }
    }
  }
  return 0;
}