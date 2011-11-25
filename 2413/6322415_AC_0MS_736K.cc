#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int last;
bool valid;
int sz(sizeof(char)*102);
struct num
{
	char number[102];
	num() {
		memset(number,0,sizeof(number));
	}
	num& operator+(num x) {
		
	}
	void eq(const num& x,const num& y) {
		last = 0;
		for(int i = 100; i >= 0; i--) {
			number[i] = x.number[i] + y.number[i] + last;
			if(number[i] >= 10) {
				number[i] -= 10;
				last = 1;
			} else
				last = 0;
		}
		if(last)
			valid = false;
	}
	void output() {
		int i=0;
		while(number[i] == 0)
			i++;
		while(i < 101)
			printf("%d",number[i++]);
		puts("");
	}
};
inline bool com(num &x, num &y,int t) {
	if(!t)
		return memcmp(x.number,y.number,sz) < 0;
	else
		return memcmp(x.number,y.number,sz) <= 0;
}
num p[500];
void init()
{
	p[0].number[100] = 1;
	p[1].number[100] = 2;
	int i;
	valid = true;
	for(i = 2;i <= 484; i++) {
		p[i].eq(p[i-1],p[i-2]);
//		p[i].output();
	}
//	cout << i << endl;
}
char a[102],b[102];
num aa,bb;
void change(char *a, char* b) {
	memset(aa.number,0,sz);
	memset(bb.number,0,sz);
	int ab(100);
	for(int i = strlen(a)-1; i >= 0; i--)
		aa.number[ab--] = a[i]-'0';
	ab = 100;
	for(int i = strlen(b)-1; i >= 0; i--)
		bb.number[ab--] = b[i]-'0';
}
int main()
{
	init();
	while(scanf("%s %s",a,b))
	{
		change(a,b);
		if(strlen(a) == 1 && aa.number[100] == 0 && strlen(b) == 1 && bb.number[100] == 0)
			return 0;
		int ca,cb;
		ca = cb = 0;
		for(int i = 0; i <= 485; i++)
			if(com(p[i] ,aa,0)) {
				ca++; cb++;
			} else if(com(p[i] , bb,1)) {
				cb++;
			} else 
				break;
		cout << cb - ca << endl;
	}

	return 0;
}
