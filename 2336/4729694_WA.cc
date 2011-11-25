#define M 1440
#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int n,m,t;
int ttime[M],arrive[M];
void input()
{
	scanf("%d%d%d",&n,&t,&m);
	for(int i = 0; i < m; i++)
		scanf("%d",&arrive[i]);
	memset(ttime,0x7f,sizeof(ttime));
}
int f()
{
	int x;
	ttime[0] = arrive[0];
	for(int i = 0; i < m ; i++)
		for(int j = 1; j <= n; j++)	{
			if(i+j > m)
				break;
			x = max(ttime[i]+2*t,arrive[j+i]);
			if(x < ttime[i+j])
				ttime[i+j] = x;
		}
	return ttime[m];
}
int main()
{
	int c; 
	scanf("%d",&c);
	while(c--)	{
		input();
		printf("%d %d\n",f(),(m+n-1)/n);
	}
	return 0;
}