#define M 1440
#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
int n,m,t;
//这里用动态规划算出最早的开始时间用ttime来记录
//arrive用来记录车到达的时间
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
	for(int i = 0; i < m ; i++)	{
		//前n个车的最早坐渡轮时间当然是让前面的车等待自己一起上
		if(i < n)
			ttime[i] = arrive[i];
		for(int j = 1; j <= n; j++)	{
			if(i+j > m)
				break;
			//穷举如果车i到达渡轮就马上开的话第i+j车最早的开船时间
			x = max(ttime[i]+2*t,arrive[j+i]);
			if(x < ttime[i+j])
				ttime[i+j] = x;
		}
	}
	//结果是最后一辆车的开船时间加上渡江需要的时间
	return ttime[m-1]+t;
}
int main()
{
	int c; 
	scanf("%d",&c);
	while(c--)	{
		input();
		//最少需要多少次只需要将m/n然后取ceiling
		printf("%d %d\n",f(),(m+n-1)/n);
	}
	return 0;
}