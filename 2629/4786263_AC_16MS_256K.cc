#include<memory.h>
#include<string.h>
#include<stdio.h>
#define min(x,y) (x>y)?y:x
int main()
{
	char x[1010],y[1010];
	int c[26],d[26];
	while(gets(x))
	{
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		gets(y);
		for(int i = 0; i < strlen(x); i++)
			c[x[i]-'a']++;
		for(int j = 0; j < strlen(y); j++)
			d[y[j]-'a']++;
		for(int i = 0; i < 26; i++){
			c[i] = min(c[i],d[i]);
			for(int j = 0; j < c[i]; j++)
				printf("%c",'a'+i);
		}
		printf("\n");
	}
	return 0;
}