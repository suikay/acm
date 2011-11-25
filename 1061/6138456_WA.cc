#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
typedef long long ll;
using namespace std;
ll x,y,m,n,l,a,b,c,tmp;
ll extend_euclid(ll a,ll b)
{
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		int r = extend_euclid(b,a%b);
		tmp = y;
		y = x - (a/b) * y;
		x = tmp;
		return r;
	}
}

int main()
{
	cin >> x >> y >> m >> n >> l;
	a = (x-y+l)%l;
	b = (n-m+l)%l;
	c = extend_euclid(l,b);
	if((a % c) != 0) 
		puts("Impossible");
	else
	{
		tmp = y*(a/c)%l;
		cout << tmp%(l/c) << endl;
	}

	return 0;
}
