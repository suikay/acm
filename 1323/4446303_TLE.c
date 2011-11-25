#include <math.h>
#include <stdio.h>
#define swap(a,b) temp = (a);(a) = (b);(b) = temp;
#define min(a,b) (a) > (b) ? b:a;
int main()
{
	int x[1000],y[1000],n,d, count = 0,time = 0;
	int now;
	int ii,temp,dS;
	scanf("%d%d",&n,&d);
	while( n > 0)
	{
		int i,j;
		count = 0;
		now = -9999999;
		dS = d * d;
		for( i = 0 ; i < n; i++) 
			scanf("%d%d",&x[i],&y[i]);
		for( i = 0; i < n;i++)
			for( j = i + 1; j < n; j++)
				if( x[i] >  x[j]) {
					swap(x[i],x[j]);
					swap(y[i],y[j]);
				}
		for( i = 0; i < n;i++)
			if(y[i] <= 0 || d <= 0 ||  y[i] > d) {
				printf("Case %d: -1\n",++time);
				break;
			}
			else {
					for( ii = 0; ( (ii * ii + y[i] * y[i])  <= dS ); ii++);
					temp = x[i]  + ii - 1;
					if(x[i] > now && ( (x[i] - now) * (x[i] - now) + y[i] * y[i] ) > dS) {
					count++;
					now = temp;
				}
				else 
					now = min(now,temp);
			}
		if (i == n)
			printf("Case %d: %d\n",++time,count);
		scanf("%d%d",&n,&d);
	}
}