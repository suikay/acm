#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#define M 10010
using namespace std;
typedef struct {
	int o;
	int d;
	int w;
}Edge;
Edge edge[M * M];
int BF(int n,int path,int des)
{
	int d[M];
	memset(d,0,sizeof(d));
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j < path; j++)
			if(d[edge[j].o] + edge[j].w > d[edge[j].d])
				d[edge[j].d] = d[edge[j].o] + edge[j].w;
	return d[des+1];
}
void input()
{
	int n,x,y,xy,el=0,max = 0;
	scanf("%d",&n);
	for(int i = 0; i <  n ;i++) {
		scanf("%d%d",&x,&y);
		if(x  > y)
			swap(x,y);
		if(y > max )
			max = y;
		edge[el].o = x;
		edge[el].d = y+1;
		edge[el++].w = 2;
	}
	for(int i = 1; i <= max; i++) {
		edge[el].o = i;
		edge[el].d = i+1;
		edge[el++].w  = 0;
		edge[el].o = i;
		edge[el].d = i-1;
		edge[el++].w = -1;
	}
	printf("%d\n",BF(n,el,max));
}
int main()
{
	input();
}