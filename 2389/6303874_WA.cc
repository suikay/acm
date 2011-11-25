#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char a[100],b[100];
int c[100];
int main()
{
	int la,lb,more;
	memset(c,0,sizeof(c));
	gets(a);
	gets(b);
	la = strlen(a);
	reverse(a,a+la);
//	a[la] = 0;
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
	/*
	for(int i = lb-1; i >= 0; i--) {
		more = 0;
		for(int j = 0; j < la; j++) {
			a[j] = a[j]*b[i]+more;
			printf("%d %d\n",j,a[j]);
//			cout << j << " " << a[j] << endl;
			more = a[j] / 10;
			a[j] %= 10;
		}
		if(more)
			a[la++] = more;
	}
	*/
	int i;
	while(i > 0 && !c[i])
		i--;
	while(i >= 0)
		putchar('0'+c[i--]);
	puts("");

	return 0;
}
