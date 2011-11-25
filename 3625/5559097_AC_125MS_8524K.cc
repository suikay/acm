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
#define dis(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
struct Edge
{
	int u,v;
	double w;
	bool operator<(const Edge &x) {
		return w > x.w;
	}
};
Edge edge[600000];
double x[1100],y[1100];
int p[1100];
int par(int x)
{
	if(p[x] < 0)
		return x;
	return (p[x] = par(p[x]));
}
int join(int x,int y)
{
	int xx,yy;
	xx = par(x);
	yy = par(y);
	if(xx != yy) 
		if(p[xx] < p[yy]) {
			p[xx] += p[yy];
			p[yy] = xx;
		} else {
			p[yy] += p[xx];
			p[xx] = yy;
		}
}
int main()
{
	int n,m,last;
	scanf("%d%d",&n,&m);
	last = n-1;
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf",x+i,y+i);
	memset(p,-1,sizeof(p));
	int xx,yy;
	for(int i = 0; i < m; i++) {
		scanf("%d%d",&xx,&yy);
		if(par(xx) != par(yy)) {
			join(xx,yy);
			last--;
		}
	}
	int pn(0);
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++) {
			edge[pn].u = i;
			edge[pn].v = j;
			edge[pn++].w = dis(x[i],y[i],x[j],y[j]);
		}
	make_heap(edge,edge+pn);
	double res(0.0);
	int u,v;
	double w;
	while(last)
	{
		u = edge[0].u;
		v = edge[0].v;
		w = edge[0].w;
		if(par(u) != par(v)) {
			join(u,v);
			res += w;
			last--;
		}
		pop_heap(edge,edge+pn);
		pn--;
	}
	printf("%.2f\n",res+10e-5);

	return 0;
}