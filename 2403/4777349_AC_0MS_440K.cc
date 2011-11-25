#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct data
{
    char names[35];
    int point;
}data;

int compare(const void *p1,const void *p2)
{
    data a=*(data *)p1;
    data b=*(data *)p2;
    if( strcmp(a.names,b.names) > 0)
        return 1;
    if( !strcmp(a.names,b.names))
        return 0;
    return -1;
}

int main()
{
  int m,n,res(0);
  char word[1000];
  data *pos,tmp;
  scanf("%d%d",&m,&n);
  data* d = new(data[m]);
  for(int i = 0; i < m; i++){
    scanf("%s%d",d[i].names,&(d[i].point));
//    cout << "\"" << d[i].names << "\"" << endl;
  }
  qsort(d,m,sizeof(data),compare);
  while(cin >> tmp.names){
    if(!strcmp(tmp.names,".")){
      cout << res << endl;
      res = 0;
      continue;
    }
    pos = (data*) bsearch(&tmp,d,m,sizeof(data),compare);
    if(!pos)
      continue;
    res += pos->point;
  }
  return 0;
}
