#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char arr[100000000];
int p[300];
int main()
{
	char m;
	for(char i = '0'; i <= '9'; i++)
		p[i] = i-'0'+1;
	p['0'] = 2;
	for(char i = 'A'; i <= 'Z'; i++)
		p[i] = i-'A'+11;
	for(char i = 'a'; i <= 'z'; i++)
		p[i] = i-'a'+37;
	while(gets(arr)) {
		m = '0';
		if(strlen(arr) > 1 && arr[0] == '0') {
			puts("such number is impossible!");
			continue;
		}
		for(char *p = arr; *p; p++)
			m = (*p > m)? *p: m;
		printf("%d\n",p[m]);
	}


	return 0;
}
