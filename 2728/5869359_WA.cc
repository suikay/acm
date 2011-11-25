#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 1100;
double dis[N][N],d[N],ls[N],hs[N];
int h[N],x[N],y[N],hd[N][N];
int n;
bool v[N];
double prim()
{
	double _min,HS,LS;
	int k;
	HS = LS = 0.0;
	v[0] = true;
	for(int i = 1; i < n; i++) {
		hs[i] = hd[i][0]; ls[i] = dis[i][0];
		d[i] = hd[i][0]/dis[i][0];
//		cout << "d["<<i<<"] " << d[i] << endl;
	}
	for(int i = 1; i < n; i++) 
	{
		_min = 10e10;
		for(int j = 1; j < n; j++)
			if(!v[j] && (d[j] < _min)) {
				_min = d[j];
				k = j;
			}
		HS += hs[k]; LS += ls[k];
//		cout << k << " " <<  _min << " " << HS << " " << LS << endl;
		v[k] = true;
		for(int j = 1; j < n; j++) 
			if(!v[j] && d[j] > ((HS+hd[k][j])/(LS+dis[k][j]))) {
				d[j] = ((HS+hd[k][j])/(LS+dis[k][j]));
				hs[j] = hd[k][j]; ls[j] = dis[k][j];
			}
	}
	return HS/LS;
}
inline bool input()
{
	scanf("%d",&n);
	if(!n)
		return false;
	for(int i = 0; i < n; i++)
		scanf("%d%d%d",x+i,y+i,h+i);
	return true;
}
void init()
{
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++) {
			dis[j][i] = dis[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			hd[j][i] = hd[i][j] = abs(h[i]-h[j]);
		}
	memset(v,false,sizeof(v));
}
int main()
{
	while(input()) {
		init();
		printf("%.3lf\n",prim());
	}

	return 0;
}
/*
4
0 0 0
0 1 1
1 1 2
1 0 3
4
0 0 0
0 1 0
1 1 0
1 0 0
0
*/
