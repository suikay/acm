#define INF 10e-3
#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int a,b,c,d;
	double p1,p2;
	while(true)
	{ 
		scanf("%d%d%d%d",&c,&d,&a,&b);
		if(a < 1)
			return 0;
		p1 = min(1.0*a/c,1.0*b/d);
		p2 = min(1.0*a/d,1.0*b/c);
		p1 = max(p1,p2);
		if(p1 >= 1.0)
			p1 = 100.1;
		else
			p1 = p1*100 + INF;
		printf("%d",(int)p1);
		cout << "%" << endl;
	}
	return 0;
}
