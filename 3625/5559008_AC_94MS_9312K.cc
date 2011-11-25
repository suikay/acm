#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define D(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
const int N = 1100;
double dis[N][N],x[N],y[N];
bool v[N];
int main()
{
	int n,m,u,tx,ty;
	double least[N],res,_min;
	bool v[N];
	memset(v,false,sizeof(v));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf",x+i,y+i);
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			dis[i][j] = dis[j][i] = D(x[i],y[i],x[j],y[j]);
	for(int i = 0; i < m; i++) {
		scanf("%d%d",&tx,&ty);
		dis[tx][ty] = dis[ty][tx] = 0.0;
	}
	for(int i = 1; i <= n; i++)
		least[i] = dis[1][i];
	v[1] = true;
	res = 0.0;
	for(int i = 1; i < n; i++) {
		_min = 0x7fffffff;
		for(int j = 2; j <= n; j++)
			if(!v[j] && least[j] < _min) {
				_min = least[j];
				u = j;
			}
		v[u] = true;
		res += _min;
		for(int j = 2; j <= n; j++)
			if(!v[j] && dis[u][j] < least[j])
				least[j] = dis[u][j];
	}
	printf("%.2f\n",res);

	return 0;
}