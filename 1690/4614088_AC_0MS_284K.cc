#include<stdio.h>
#include<memory.h>
#include<string.h>
char s[2600];
bool get[2600];
int time,p;
char c;
int findback(int x)
{
	int top(1);
	for(int j = x+1; j < p; j++)
	if(s[j]=='(')
		top++;
	else
		if(s[j]==')')	{
		top--;
		if(!top)
			return j;
	}
	return 0;
}
char front(int x)
{
	for(int i = x-1; i >= 0; i--)
		if(get[i])
			return s[i];
}
int main()
{
	char data[10000];
	scanf("%d",&time);
	gets(data);
	while(time--)	{
		memset(get,true,sizeof(get));
		p = 1;
		s[0]='+';
		gets(data);
		for(int i = 0; i < strlen(data);i++)
			if(data[i]!=' ')
				s[p++] = data[i];
		s[p]='\0';
		for(int i = 1; i < p; i++){
			if(s[i]=='('){
				int tmp = findback(i);
				if(front(i)!='-'){
					get[i]=false;
					get[tmp]=false;
				}
				else {	//A-(((B-C)-D))
					if(((s[i+1]=='(')&&(findback(i+1)== (tmp-1)))
						|| ((i+1)==(tmp-1)))
						get[i]=get[tmp]=false;
				}
			}
			if(get[i])
				printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}

