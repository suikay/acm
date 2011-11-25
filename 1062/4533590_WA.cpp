#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define INFINITY 999999999
#define ABS(x) (x) > 0? (x):(-(x))
using namespace std;
int minLevel;
int price[101];
int l[101];
int road[101][101];
int d[101];
void ShortestPath_DIJ(int n) 
{
	bool final[101];
	int min,v;
	memset(final,0,sizeof(bool) * 101);
	for(int i = 1; i <= n; i++)
		d[i] = road[1][i];
	final[1] = true;
	for(int i = 1; i <= n; i++) {
		min = INFINITY;
		v = 0;
		for(int w = 2; w <= n;w++)
			if(!final[w] && (ABS(l[1] - l[w]) <= minLevel) && d[w] < min) {
				min = d[w];
				v = w;
			}
		if(!v)
			break;
		final[v] = true;
		for( int w = 1 ; w <= n; w++)
			if(!final[w] && (ABS(l[1] - l[w]) <= minLevel)  && (d[v] + road[v][w] < d[w]))
				d[w] = d[v] + road[v][w];
	}
}				
int main()
{
	int m,n,k,o;
	cin >> minLevel >> n;
	for(int i =1 ;i <= n; i++)
		for(int j = 1; j <= n; j++)
			road[i][j] = INFINITY;
	road[1][1] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> price[i] >> l[i] >> k;
		for(int j = 1; j <= k ; j++) {
			cin >> o ;
			cin >> road[i][o];
		}
	}
	ShortestPath_DIJ(n);
	int low=999999999;
	for(int i = 1 ; i <= n; i++) 
		if(ABS(l[i]-l[1]) <= minLevel && (d[i] + price[i] < low))
			low = d[i] + price[i];
	printf("%d\n",low);
	return 0;
}
