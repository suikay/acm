#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
char ori[110];
int main()
{
	int sz;
	gets(ori);
	sz = strlen(ori);
	bool a,b,p;
	a = b = false;
	for(int i = 0; i < sz; i++) 
		if(ori[i] == '_')
			a = true;
		else if(ori[i]  <= 'Z')
			b = true;
	p = a && b;
	if(ori[0] <= 'Z')
		p = true;
	if(ori[0] == '_' || ori[sz-1] == '_')
		p = true;
	for(int i = 1; i < sz; i++)
		if(ori[i] == '_' && ori[i-1] == '_')
			p = true;
	if(p) {
		puts("Error!");
		return 0;
	}
	if(a) {
		for(int i = 0; i < sz; i++)
			if(ori[i] == '_') {
				if(i < (sz-1)) {
					putchar(ori[i+1]-'a'+'A');
					i++;
				}
			} else
				putchar(ori[i]);
	}
	else {
		for(int i = 0; i < sz; i++)
			if(ori[i] <= 'Z') {
				putchar('_');
				putchar(ori[i]-'A'+'a');
			} else 
				putchar(ori[i]);
	}
	putchar('\n');

	return 0;
}