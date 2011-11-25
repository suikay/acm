#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
#define CHG(x) (x-'0')
int ori[200], tmp[200];
int cnt[20];
void check(int x)
{
	bool ok = true;
	int last;
	while(ok)
	{
		last = 0;
		for(int i = 0; i < 200; i++) 
		{
			tmp[i] = (last * 100000 + ori[i]) / x;
			last = ori[i] + last*100000 - tmp[i]*x;
		}
		if(!last) {
			memcpy(ori,tmp,sizeof(tmp));
			cnt[x]++;
		}
		else
			ok = false;
	}
}
void output(int x)
{
	for(int i = 0; i < cnt[x]; i++)
		putchar(x+'0');
}
bool ans() 
{
	for(int i = 0; i < 199; i++)
		if(ori[i])
			return false;
	if(ori[199] != 1)
		return false;
	return true;
}
char str[1100];
bool input(int &cc)
{
	gets(str);
	if(str[0] == '-')
		return false;
	if(strlen(str) == 1)
		cc = str[0] - '0';
	else
		cc = -1;
	reverse(str,str+strlen(str));
	for(int i = strlen(str); i < 1000; i++)
		str[i] = '0';
	str[1000] = '\0';
	reverse(str,str+1000);
	for(int i = 0; i < 200; i++)
		ori[i] = CHG(str[i*5])*10000 + CHG(str[i*5+1])*1000 + + CHG(str[i*5+2])*100 + CHG(str[i*5+3])*10 + CHG(str[i*5+4]);
	return true;
}
int main()
{
	int cc;
	while(input(cc))
	{
		if(cc != -1) {
			printf("1%d\n",cc);
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		for(int i = 9; i > 1; i--)
			check(i);
		if(ans() == false)
			puts("There is no such number.");
		else {
			for(int i = 2; i < 10; i++)
				output(i);
			puts("");
		}
	}

	return 0;
}
