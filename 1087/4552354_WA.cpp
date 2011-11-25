#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n;
	double b,up,down;
	while(scanf("%d",&n) && n) 
	{
		//int x,y;
		if( n > 0 ) 
		{
			for(int i = 32; i > 0; i--) 
			{
				b = pow(n,1.0/i);
				//y = x + 1;
				if(fabs(b-(int)b) < 10e-12) {
					printf("%d\n",i);
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
				if(fabs(b-(int)b) <= 10e-12) {
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}

