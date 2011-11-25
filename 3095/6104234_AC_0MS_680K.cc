#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
double res,ori;
int len;
char p[100];
void f(int pos,int dir,double pp)
{
	if(pos == -1 || pos == len || p[pos] == '.') {
		res += pp;
		return ;
	}
	if(dir == 0) {
		if(p[pos] == '_')
			return;
		else if(p[pos] == '/')
			f(pos-1,-1,pp);
		else if(p[pos] == '\\')
			f(pos+1,1,pp);
		else {
			f(pos-1,-1,pp/2);
			f(pos+1,1,pp/2);
		}
	} else {
		if(p[pos] == '_')
			f(pos+dir,dir,pp);
		else
			return;
	}
}		
int main()
{
	while(true) {
		scanf("%s",p);
		if(p[0] == '#')
			return 0;
		len = strlen(p);
		res = 0.0;
		ori = 1.0/len;
		for(int i = 0; i < len; i++)
			f(i,0,ori);
		printf("%d\n",(int)(res*100.0));
	}

	return 0;
}
