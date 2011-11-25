#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define N 2100000
using namespace std;
int l[N],r[N],v[N];
int mix[N];
void build(int x,int y,int no)
{
	l[no] = x; r[no] = y;
	if(x+1 == y)
		return;
	build(x,(x+y)>>1,no<<1);
	build((x+y)>>1,y,(no<<1)+1);
}
void add(int x,int y,int no,int area)
{
	//cout << "ADD " << x << " " << y << " " << no << " " << area << endl;
	//cout << l[no] << " " << r[no] << " " << mix[no] << endl;
	int tmp;
	tmp = no << 1;
	v[no] += area*(y-x);
	if(mix[no] >= 0)
		if(x == l[no] && y == r[no])
		{
			mix[no] += area;
			return;
		}
		else 
		{
			if(mix[no] != 0) {
				add(l[tmp],r[tmp],tmp,mix[no]);
				add(l[tmp+1],r[tmp+1],tmp+1,mix[no]);
			}
		}
	mix[no] = -1;
	if(x >= r[tmp]) {
		add(x,y,tmp+1,area);
	} else if(y <= l[tmp+1]) {
		add(x,y,tmp,area);
	} else {
		add(x,r[tmp],tmp,area);
		add(l[tmp+1],y,tmp+1,area);
	}
	//cout << " BACK " << endl;
}

double cnt(int last,int no)
{
	if(v[no] < last)
		return -1.0;
	if(v[no] == last && mix[no] >= 0)
		return r[no]*1.0;
	if(mix[no] > 0)
		return last*1.0/mix[no]+l[no];
	if(v[no<<1] < last)
		return cnt(last-v[no<<1],(no<<1)+1);
	return cnt(last,no<<1);
}
void init() {
	memset(v,0,sizeof(v));
	memset(mix,0,sizeof(mix));
}
int main()
{
	build(0,1050000,1);
	int t,n,b,h,w,d,v;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d%d",&b,&h,&w,&d);
			add(b,b+h,1,w*d);
		}
		scanf("%d",&v);
		double tmp = cnt(v,1);
		if(tmp < 0.0)
			puts("OVERFLOW");
		else
			printf("%.2f\n",tmp);
	}

	return 0;
}
/*
3
4
11 7 5 1
15 6 2 2
5 8 5 1
19 4 8 1
78
*/