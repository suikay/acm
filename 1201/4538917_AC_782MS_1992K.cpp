#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#define M 50010
using namespace std;
int f[100*M],t[100*M],w[100*M];
//typedef struct 
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
	return d[des];
}
void input()
{
	int n,x,y,xy,el=0,max = 0,start = 999999999;
	bool in[M];
	scanf("%d",&n);
	for(int i = 0; i <  n ;i++) {
		scanf("%d%d%d",&x,&y,&xy);
		in[x]=in[y+1]=true;
		if(x  > y)
			swap(x,y);
		if( start > x)
			start = x;
		if(y + 1 > max )
			max = y+1;
		f[el] = x;
		t[el] = y+1;
		w[el++] = xy;
	}
	/*
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
	*/
	int last = 0;
	if(start == 0)
		start++;
	for(int i = start; i <= max; i++) 
		if(in[i]) {
			f[el] = last;
			t[el] = i;
			w[el++]  = 0;
			f[el] = i;
			t[el] = last;
			w[el++]  = last - i;
			last = i;
	}
	printf("%d\n",BF(n,el,max));
}
int main()
{
	input();
}
