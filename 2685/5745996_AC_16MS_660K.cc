#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int get(char x[])
{
	int len = strlen(x),now,res(0);
	now = 1;
	for(int i = 0; i < len; i++) {
		if(x[i] < 'A') 
			now = x[i] - '0';
		else {
			switch(x[i]) {
			case 'm': 
				res += 1000 * now;break;
			case 'c':
				res += 100*now; break;
			case 'x':
				res += 10*now; break;
			case 'i':
				res += now; break;
			}
			now = 1;
		}
	}
	return res;
}
char put(int x)
{
	if(x >= 2000)
		putchar(x/1000 + '0');
	if(x >= 1000)
		putchar('m');
	x %= 1000;
	if(x >= 200)
		putchar(x/100 + '0');	
	if(x >= 100)
		putchar('c');
	x %= 100;
	if(x >= 20)
		putchar(x/10 + '0');	
	if(x >= 10)
	putchar('x');
	x %= 10;
	if(x >= 2)
		putchar(x + '0');	
	if(x >= 1)
		putchar('i');
	puts("");
}

	
int main()
{
	int k;
	char a[100],b[100];
	cin >> k;
	while(k--)
	{
		cin >> a >> b;
		put(get(a)+get(b));
	}

	return 0;
}