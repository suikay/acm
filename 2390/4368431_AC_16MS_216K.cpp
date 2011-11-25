#include <stdio.h>
#include <math.h>
int main()
{
	int r,m,y;
	scanf("%d%d%d",&r,&m,&y);
	printf("%d",(int) (m * pow((1.0 + r/100.0),y)));
	return 0;
}
