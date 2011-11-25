#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#define M 50050
#define N 500
using namespace std;
int f[M*N],t[M*N],w[M*N];
int BF(int n,int path,int des)
{
	int d[M];
	bool ok=true;
	memset(d,0,sizeof(d));
	for(int i = 1;ok && i <= n; i++)  {
		ok = false;
		for(int j = 0; j < path; j++)
			if(d[f[j]] + w[j] > d[t[j]]) {
				ok = true;
				d[t[j]] = d[f[j]] + w[j];
			}
	}
	return d[des+1];
}
void input()
{
	int n,x,y,xy,el=0,max = 0,start = 999999999;
	scanf("%d",&n);
	for(int i = 0; i <  n ;i++) {
		scanf("%d%d%d",&x,&y,&xy);
		if(x  > y)
			swap(x,y);
		if( start > x)
			start = x;
		if(y + 1 > max )
			max = y;
		f[el] = x;
		t[el] = y+1;
		w[el++] = xy;
	}
	for(int i = start; i <= max; i++) {
		f[el] = i;
		t[el] = i+1;
		w[el++]  = 0;
	}
	for(int i = start + 1; i <= max; i++) {
		f[el] = i;
		t[el] = i-1;
		w[el++] = -1;
	}
	printf("%d\n",BF(n,el,max));
}
int main()
{
	input();
}
