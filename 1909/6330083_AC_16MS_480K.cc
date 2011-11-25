#include <stdio.h>
#include <stdlib.h>
#define N 10010
int p[N], son[N], m[N];
int main()
{
  int n,cnt,res,tmp,dummy;
  while(scanf("%d",&n) && n) {
    cnt = 1;
    res = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d%d%d",&dummy,&m[i],&son[i]);
      //puts(" a ");
      m[i]--;
      for(int j = 0; j < son[i]; j++) {
        scanf("%d",&tmp);
        p[tmp] = i;
      }
      //puts(" B");
    }
    while(cnt < n) {
      for(int i = 1; i <= n; i++)
        if(!son[i]) {
          res += abs(m[i]);
          m[p[i]] += m[i];
          son[p[i]]--;
          son[i]--;
          cnt++;
        }
    }
    printf("%d\n",res);
  }
  return 0;
}
