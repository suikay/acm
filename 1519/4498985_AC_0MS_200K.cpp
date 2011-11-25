#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	char c;
	int s,t;
	while(true) {
		c = getchar();
		if(c == '0')
			break;
		s = 0;
		while( c != '\n') {
			s += c - '0';
			c = getchar();
		}
		while( s > 9) {
			t = 0;
			while (s) {
				t += s % 10;
				s /= 10;
			}
			s = t;
		}
		printf("%d\n",s);
	}
}