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
int p[300],pp[300];
int main()
{
	char m;
	int now,res;
	for(char i = '0'; i <= '9'; i++) {
		p[i] = i-'0'+1;
		pp[i] = i-'0';
	}
	p['0'] = 2;
	for(char i = 'A'; i <= 'Z'; i++) {
		p[i] = i-'A'+11;
		pp[i] = i-'A'+10;
	}
	for(char i = 'a'; i <= 'z'; i++) {
		p[i] = i-'a'+37;
		pp[i] = i-'a'+36;
	}

	while(gets(arr)) {
		m = '0';
/*		if(strlen(arr) > 1 && arr[0] == '0') {
			puts("such number is impossible!");
			continue;
		}*/
		for(char *ptr = arr; *ptr; ptr++)
			m = (*ptr > m)? *ptr: m;
		int i;
		for(i = p[m]; i <= 62; i++) {
			res = 0;
			now = 1;
			for(char *ptr = arr+strlen(arr)-1;now && ptr >= arr; ptr--) {
				res += now*(pp[*ptr]);
				now = now * i % (i-1);
			}
			if(res % (i-1) == 0)
				break;
		}
		if(i > 62)
			puts("such number is impossible!");
		else
			printf("%d\n",i);
	}

	return 0;
}
