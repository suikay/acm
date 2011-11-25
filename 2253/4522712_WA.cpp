#include<iostream>
#include<stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;
#define INFINITY 9999999.9
#define max(x,y) (x) > (y) ? (x):(y);
typedef struct Stone {
	int x;
	int y;
}Stone;
Stone stone[201];
double road[201][201];
double d[201];
void ShortestPath_DIJ(int n)
{
	int v;
	bool final[1001];
	for(int i = 1; i <= n; i++) {
		final[i] = false;
		d[i] = road[1][i];
	}
	d[1] = 0; 
	final[1] = true;
	double min;
	for(int i = 1; i <= n; i++) {
		min = INFINITY;
		for(int w = 1; w <= n; w ++)
			if(!final[w] && d[w]  < min ) {
					v = w;
					min = d[w];
				}
		final[v] = true;
		for(int w = 1; w <= n; w++)
			 if(!final && ( min < d[w] && road[v][w] < d[w]))
					d[w] =max( road[v][w] , min);
	}
}
int main()
{
	int n,time = 1;
	while(cin >> n && n) {
		/*
		cin >> stone[1].x >> stone[1].y;
		cin >> stone[n].x >> stone[n].y;
		*/
		for(int i = 1; i <= n; i++) 
			cin >> stone[i].x >> stone[i].y;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if( i == j)
					road[i][j] = INFINITY;
				else
					road[i][j] = road[j][i] = sqrt(1.0*(stone[i].x - stone[j].x)*(stone[i].x - stone[j].x) + (stone[i].y - stone[j].y) * (stone[i].y - stone[j].y));
		ShortestPath_DIJ(n);
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",time++,d[n]);
	}
}