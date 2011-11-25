#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define N 110
#define NIL 99999999
int path[2*N];
int edge[N][N];
int n,np,nc,rc;
#define min(x,y) (x)>(y)?(y):(x);
bool input()
{
	int x,y,z;
	memset(edge,0,sizeof(edge));
	if(scanf("%d%d%d%d",&n,&np,&nc,&rc)!= 4)
		return false;
	for(int i = 0; i < rc; i++) {
		scanf(" (%d,%d)%d",&x,&y,&z);
		edge[x+1][y+1] = z;
	}
	for(int i = 0; i < np;i++) {
		scanf(" (%d)%d",&x,&y);
		edge[0][x+1] = y;
	}
	for(int i = 0; i < nc; i++) {
		scanf(" (%d)%d",&x,&y);
		edge[x+1][n+1] = y;
	}
	return true;
}
int findpath()
{
	int queue[N],h,t;
	int k;
	int d[N];
	memset(d,0,sizeof(d));
	memset(path,-1,sizeof(path));;
	d[0] = NIL;
	h = t = 0;
	queue[t++] = 0;
	path[0] = 0;
	while(h!= t) {
		k = queue[h++];
		if(k == n+1)
			break;
		for(int i = 1; i <= n+1; i++)
			if(d[k] > 0 && path[i] == -1 && edge[k][i] > 0) {
				d[i] = min(d[k],edge[k][i]);
				path[i] = k;
				queue[t++] = i;
			}
	}
	if(path[n+1] == -1)
		return -1;
	return d[n+1];
}
int FF()
{
	int step,res=0;
	while((step = findpath())!=-1) {
		res+= step;
		int l = n+1;
		while(l) {
			edge[path[l]][l] -= step;
			edge[l][path[l]] += step;
		l = path[l];
		}
	}
	return res;
}
int main()
{
	while(input())
		printf("%d\n",FF());
	return 0;
}