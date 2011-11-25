#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int in[751];
int inv[751];
int x[751];
int y[751];
unsigned int road[751][751];
int main()
{
	int iCity;
	scanf("%d",&iCity);
	for( int i = 1; i <= iCity;i++)
		scanf("%d%d",&x[i],&y[i]);
	for( int i = 1; i <= iCity; i++)
		for( int j = 1; j <= iCity; j++)
			road[i][j] = (x[i] - x[j] ) * (x[i] - x[j]) + (y[i] - y[j]) * ( y[i] - y[j]);
	int iHighway;
	int xx,yy;
	scanf("%d",&iHighway);
	for( int i = 1; i <= iHighway; i++) {
		scanf("%d%d",&xx,&yy);
		road[xx][yy] = road[yy][xx] = 0;
	}
	in[0] = 1;
	inv[1] = 1;
	int count = 1;
	int min,minx,miny;
	for( int i = 1; i <= iCity - 1; i++) {
		min = 9999999;
		for( int j = 0; j < count; j++)
			for( int k = 1; min && k <= iCity; k++)
				if( !inv[k] &&  road[(in[j])][k] < min) {
					min = road[(in[j])][k];
					minx = in[j];
					miny = k;
				}
		in[count++] = miny;
		inv[miny] = 1;
		if(min)
			printf("%d %d\n",minx,miny);
	}
}