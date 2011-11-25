#include<string.h>
#include<stdio.h>
int main()
{
  char data[1000],dummy[100];
  while(gets(dummy))
  {
    if(dummy[0]!='S')
      break;
    gets(data);
    for(int i = 0; i < strlen(data); i++){
      if(data[i]>'Z' || data[i]<'A')
        continue;
      if(data[i]<='E')
        data[i] = 'V' + data[i] - 'A';
      else
        data[i] = -'F' + data[i] + 'A';
    }
    puts(data);
    gets(dummy);
  }
  return 0;
}
