#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char tmp[10000];
int main()
{
	int l,cnt = 0;
	while(gets(tmp))
	{
		l = strlen(tmp);
		for(int i = 0; i < l; i++) {
			if(tmp[i] != '"')
				putchar(tmp[i]);
			else {
				if(!cnt) {
					putchar('`'); 
					putchar('`');
					cnt = 1;
				} else {
					putchar('\'');
					putchar('\'');
					cnt = 0;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
