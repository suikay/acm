#include <math.h>
#include <stdio.h>
#define swap(a,b) temp = (a);(a) = (b);(b) = temp;
#define min(a,b) (a) > (b) ? b:a;
int getx(int x,int y,int d)
{
	int i;
	for( i = 0; ( (i * i + y * y)  <= d * d ); i++);
	return x + i - 1;
}
int main()
{
	int x[1000],y[1000],n,d, count = 0,time = 0;
	int now;
	scanf("%d%d",&n,&d);
	while( n > 0)
	{
		int i,j,temp;
		count = 0;
		now = -9999999; 
		for( i = 0 ; i < n; i++) 
			scanf("%d%d",&x[i],&y[i]);
		for( i = 0; i < n;i++)
			for( j = i + 1; j < n; j++)
				if( x[i] >  x[j] ||(x[i] == x[j] && y[i] < y[j])) {
					swap(x[i],x[j]);
					swap(y[i],y[j]);
				}
		for( i = 0; i < n;i++)
			if( abs(y[i]) > abs(d) || d <= 0) {
				printf("Case %d: -1\n",++time);
				break;
			}
			else
				if(x[i] > now && ( (x[i] - now) * (x[i] - now) + y[i] * y[i] ) > d * d) {
					count++;
					now = getx(x[i],y[i],d);
				}
				else 
					now = min(now,getx(x[i],y[i],d));
		if (i == n)
			printf("Case %d: %d\n",++time,count);
		scanf("%d%d",&n,&d);
	}
}