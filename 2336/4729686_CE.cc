#define M 1440
#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int n,m,t;
int time[M],arrive[M];
void input()
{
	scanf("%d%d%d",&n,&t,&m);
	for(int i = 0; i < m; i++)
		scanf("%d",&arrive[i]);
	memset(time,0x7f,sizeof(time));
}
int f()
{
	int x;
	time[0] = arrive[0];
	for(int i = 0; i < m ; i++)
		for(int j = 1; j <= n; j++)	{
			if(i+j > m)
				break;
			x = max(time[i]+2*t,arrive[j+i]);
			if(x < time[i+j])
				time[i+j] = x;
		}
	return time[m];
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
/*
1
2 10 3
10
30
40
*/