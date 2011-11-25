#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int lcd(int a,int b)
{
	if(b == 0)
		return a;
	return lcd(b,a%b);
}
int main()
{
	int x,y,m,n,l,a,b,c;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	if(x > y)
		a = (x - y) % l;
	else
		a = (y - x) % l;
	if(m > n)
		b = (m - n) % l;
	else
		b = (n - m) % l;
	c = lcd(l,b);
	if((a % c) != 0 && (l - a) % c != 0) 
		puts("Impossible");
	else
	{
		long long t(1);
		while((x+m*t)%l != (y+n*t)%l && t < l)
			t++;
		cout << t << endl;
	}

	return 0;
}
