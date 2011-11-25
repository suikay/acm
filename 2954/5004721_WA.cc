#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int _tmp;
void swap(int &x,int &y)
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

int area(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int xa = x1-x2,xb = y1-y2;
	int ya = x3-x2,yb = y3-y2;
	return abs(xa*yb - xb*ya);
}

int main()
{
	int line,darea;
	int x1,y1,x2,y2,x3,y3;
	while(true)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(!x1 && !y1 && !x2 && !y2 && !x3 && !y3)
			return 0;
		line = l(x1-x2,y1-y2) + l(x1-x3,y1-y3) + l(x2-y3,y2-y3);
		darea = area(x1,y1,x2,y2,x3,y3);
		printf("%d\n",(darea + 2 - line)/2);
	}
	return 0;
}