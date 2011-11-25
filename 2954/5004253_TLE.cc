#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define swap(x,y) _tmp=x;x=y;y=_tmp;
int _tmp;
int gcd(int x,int y)
{
	if(x > y)
		swap(x,y);
	if(!(y % x))
		return x;
	return gcd(y%x,x);
}

int l(int x,int y)
{
	if(!x || !y)
		return abs(x+y);
	return gcd(abs(x),abs(y));
}

double area(int a,int b,int c,int d,int e,int f)
{
	int x1 = a-c,x2 = b-d;
	int y1 = e-c,y2 = f-d;
	return fabs(1.0*x1*y2-x2*y1)/2;
}

int main()
{
	double line,darea;
	int a,b,c,d,e,f;
	while(true)
	{
		cin >> a >> b >> c >> d >> e >> f;
		if(!a && !b && !c && !d && !e && !f)
			return 0;
		line = l(a-c,b-d) + l(a-e,b-f) + l(c-e,d-f);
		line /= 2;
		darea = area(a,b,c,d,e,f);
		cout << (int)(darea + 1.1 - line) << endl;
	}
	return 0;
}