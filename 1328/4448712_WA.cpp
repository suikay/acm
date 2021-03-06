#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) temp = (a);(a) = (b);(b) = temp;
#define min(a,b) (a) > (b) ? b:a;
typedef struct {
	int x;
	int y;
	int temp;
} point;
int compare(const void *p1,const void *p2)
{
	point a=*(point *)p1;
	point b=*(point *)p2;
	if(a.x>b.x)
		return 1;
	return -1;
}
int main()
{
	point p[1000];
	int count = 0,time = 0;
	int now,n,d;
	int temp,dS;
	scanf("%d%d",&n,&d);
	while( n > 0)
	{
		int i;
		count = 0;
		now = -9999999;
		dS = d * d;
		for( i = 0 ; i < n; i++)  {
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].temp = sqrt(1.0 * abs( dS - p[i].y * p[i].y) )+ 10e-3;
		}
		qsort(p,n,sizeof(point),compare);
		for( i = 0; i < n;i++)
			if( d <= 0 ||  p[i].y > d) {
				printf("Case %d: -1\n",++time);
				break;
			}
			else {
					if( abs( now - p[i].x) > p[i].temp && p[i].x > now) {
						count++;
						now = p[i].x + p[i].temp ;
					}
					else 
						now = min(now,p[i].x + p[i].temp );
			}
		if (i == n)
			printf("Case %d: %d\n",++time,count);
		scanf("%d%d",&n,&d);
	}
}