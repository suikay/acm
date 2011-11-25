#define INF 10e-2
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	double a,b,c,d;
	double p1,p2;
	while(true)
	{ 
		cin >> c >> d >> a >> b;
		if(a < 1)
			return 0;
		p1 = min(1.0*a/c,1.0*b/d);
		p2 = min(1.0*a/d,1.0*b/c);
		p1 = max(p1,p2)*100.0 + INF ;
		if(p1 < 1.0)
			p1 = 1.1;
		if(p1 > 100.0)
			p1 = 100.1;
		printf("%d%%\n",(int)p1);
	}
	return 0;
}
