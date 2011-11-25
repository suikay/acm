#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int p[] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
int main()
{
	char x[100],last;
	while(gets(x))
	{
		last = -1;
		for(int i = 0; i < strlen(x); i++) {
			if(last != p[x[i]-'A']) {
				if(p[x[i]-'A'])
					putchar('0'+p[x[i]-'A']);
			}
			last = p[x[i]-'A'];
		}
		puts("");
	}

	return 0;
}