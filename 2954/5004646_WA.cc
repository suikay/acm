#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int _tmp;
void swap(int &x,int y)
{
	_tmp = x;
	x = y;
	y = _tmp;
}
int gcd(int x,int y)
{
	int r;
	if(x > y)
		swap(x,y);
	while((r = y % x) != 0)
	{
		y = x;
		x = r;
	}
	return x;
}

int l(int x,int y)
{
	if(!x || !y)
		return abs(x+y);
	return gcd(abs(x),abs(y));
}

int area(int a,int b,int c,int d,int e,int f)
{
	int x1 = a-c,x2 = b-d;
	int y1 = e-c,y2 = f-d;
	return int(fabs(1.0*x1*y2 - 1.0*x2*y1)/2.0+0.1);
}

int main()
{
	int line,darea;
	int a,b,c,d,e,f;
	while(true)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(!a && !b && !c && !d && !e && !f)
			return 0;
		line = l(a-c,b-d) + l(a-e,b-f) + l(c-e,d-f);
		line /= 2;
		darea = area(a,b,c,d,e,f);
		printf("%d\n",(int)(darea + 1 - line));
	}
	return 0;
}