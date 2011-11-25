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
unsigned int x,y,m,n,l,a,b,c,xx,yy,tmp;
void extend_euclid(int x,int y)
{
	if(y == 0) {
		xx = 1;
	} else {
		extend_euclid(y,x%y);
		tmp = yy;
		yy = xx - (x / y) * yy;
		xx = tmp;
	}
}

int main()
{
	scanf("%u%u%u%u%u",&x,&y,&m,&n,&l);
	a = (x-y+l)%l;
	b = (n-m+l)%l;
	c = lcd(l,b);
	if((a % c) != 0) 
		puts("Impossible");
	else
	{
		extend_euclid(l,b);
		cout << yy*(a/c)%l << endl;
	}

	return 0;
}
