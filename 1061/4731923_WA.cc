#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a%b)
		return gcd(b,a%b);
	return b;
}
int main()
{
	int x,y,m,n,l;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	if(x>y)	{
		swap(x,y);
		swap(m,n);
	}
	int dis = y - x;
	if(m > n)	{
		int sd = m - n; 
		int left = gcd(l,dis);
		int _gcd = gcd(left,sd);
		left /= _gcd;
		sd /= _gcd;
		if(left - sd)
			if((left*sd-dis)%l)
				printf("Impossible\n");
			else
				printf("%d\n",left);
		else
				printf("%d\n",dis/gcd(dis,l));
			
	}
	else
		if(m < n)	{
			int sd = n - m; 
			int left = gcd(l,dis);
			int _gcd = gcd(left,sd);
			left /= _gcd;
			sd /= _gcd;
			if(left - sd)
				if((left*sd+dis)%l)
					printf("Impossible\n");
				else
					printf("%d\n",left);
			else	{
				left *= _gcd;
				int x = (dis+l-1)/l;
				printf("%d\n",(x*l - dis)/left);
			}
		}
		else
			printf("Impossible\n");
	return 0;
}