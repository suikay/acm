#include <math.h>
#include <stdio.h>
#define swap(a,b) temp = (a);(a) = (b);(b) = temp;
int getx(int x,int y,int d)
{
	int i;
	for( i = 0; ( (i * i + y * y)  <= d * d ); i++);
	return x + i - 1;
}
int main()
{
	int x[1000],y[1000],n,d, count = 0,time = 0;
	int lastx;
	scanf("%d%d",&n,&d);
	while( n > 0)
	{
		int i,j,temp;
		count = 0;
		lastx = -9999999; 
		for( i = 0 ; i < n; i++) 
			scanf("%d%d",&x[i],&y[i]);
		for( i = 0; i < n;i++)
			for( j = i + 1; j < n; j++)
				if( x[i] >  x[j]) {
					swap(x[i],x[j]);
					swap(y[i],y[j]);
				}
		for( i = 0; i < n;i++)
			if( abs(y[i]) > abs(d)) {
				printf("Case %d: -1\n",++time);
				break;
			}
			else
				if((( x[i] - lastx ) * ( x[i] - lastx) + y[i] * y[i]) > d * d ) {
					count++;
					lastx = getx(x[i],y[i],d);
				}
		if (i == n)
			printf("Case %d: %d\n",++time,count);
		scanf("%d%d",&n,&d);
	}
}