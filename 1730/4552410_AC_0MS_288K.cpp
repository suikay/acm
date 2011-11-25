#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	long x,y;
	double n,b,up,down;
	while(cin >> n && n) 
	{
		if( n > 0 ) 
		{
			for(int i = 32; i > 0; i--) 
			{
				b = pow(n,1.0/i);
				x = b;
				y = x + 1;
				if((b - x <= 1e-12) || ( y - b <= 1e-12)) {
					cout << i << endl;
					break;
				}
			}
		}
		else
		{
			n = -n;
			for(int i = 31; i >= 1;i-=2)
			{
				b = pow(n,1.0/i);
				x = b;
				y = x + 1;
				if((b - x <= 1e-12 ) || (y - b <= 1e-12)) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}

