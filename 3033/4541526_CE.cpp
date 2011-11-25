#include <stdio.h>
#include <memory.h>
#define N 1010
#define M 40040
int u[M],v[M],w[M];
int n,ml,md,el = 0;
void input()
{
	scanf("%d%d%d",&n,&ml,&md);
	for(int i = 0; i < ml; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		u[el]=x;
		v[el]=y;
		w[el++]=xy;
		u[el]=y;
		v[el]=x;
		w[el++]=xy;
	}
	for(int i = ml; i <ml + md; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		u[el]=x;
		v[el]=y;
		w[el++]=-xy;
		u[el]=y;
		v[el]=x;
		w[el++]=-xy;
	}
}
long long d[N];
void BF()
{
	
