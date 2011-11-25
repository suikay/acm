
#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char a[100],b[100];
int c[100];
void swap(char *x, char *y)
{
	char tmp = (*x);
	*x = *y;
	*y = tmp;
}
void reverse(char* x, char* y)
{
	y--;
	while(x < y)
		swap(x++,y--);
}
int main()
{
	int la,lb,more;
	memset(c,0,sizeof(c));
	scanf("%s",a);
	scanf("%s",b);
	la = strlen(a);
	reverse(a,a+la);
	lb = strlen(b);
	for(int i = 0; i < la; i++)
		a[i] -= '0';
	for(int i = 0; i < lb; i++)
		b[i] -= '0';
	reverse(b,b+lb);
	for(int i = 0; i < la; i++)
		for(int j = 0; j < lb; j++)
			c[i+j] += a[i]*b[j];
	for(int i = 0; i < la+lb; i++) {
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	int i(90);
	while(i > 0 && !c[i])
		i--;
	while(i >= 0)
		putchar('0'+c[i--]);
	puts("");

	return 0;
}
/*
9999999999999999999999999999999999999999
9999999999999999999999999999999999999999
1000000000000000000000000000000000000000
1000000000000000000000000000000000000000
*/