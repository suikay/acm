#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#define M 10010
using namespace std;
int f[M],t[M],w[M];
int BF(int n,int path,int des)
{
	int d[M];
	memset(d,0,sizeof(d));
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j < path; j++)
			if(d[f[j]] + w[j] > d[t[j]])
				d[t[j]] = d[f[j]] + w[j];
	return d[des+1];
}
void input()
{
	int n,x,y,xy,el=0,max = 0;
	scanf("%d",&n);
	for(int i = 0; i <  n ;i++) {
		scanf("%d%d",&x,&y);
		if(x  > y)
			swap(x,y);
		if(y + 1 > max )
			max = y;
		f[el] = x;
		t[el] = y+1;
		w[el++] = 2;
	}
	for(int i = 1; i <= max; i++) {
		f[el] = i;
		t[el] = i+1;
		w[el++]  = 0;
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
