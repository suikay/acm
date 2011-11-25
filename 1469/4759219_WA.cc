#include<memory.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Course{
  int stu[301];
  int stuNum;
  bool operator()(Course a,Course b)
  {
    return a.stuNum < b.stuNum;
  }
};
Course course[101];

int p,n;
bool v[301];

bool dfs(int pos)
{
  if(pos == p)
    return true;
  for(int i = 0; i < course[pos].stuNum; i++)
    if(!v[course[pos].stu[i]]){
      v[course[pos].stu[i]] = true;
      if(dfs(pos+1))
        return true;
      v[course[pos].stu[i]] = false;
    }
  return false;
}

int main()
{
  int t,tmp;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&p,&n);
    if(p != n){
      printf("NO\n");
      continue;
    }
    memset(v,false,sizeof(v));
    for(int i = 0; i < p; i++)  {
      scanf("%d",&course[i].stuNum);
      tmp = course[i].stuNum;
      for(int j = 0; j < tmp; j++)
        scanf("%d",&course[i].stu[j]);
    }
      sort(course,course+n,Course());
    if(dfs(0))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
