#include <stdio.h>
#include <memory.h>
#define NIL 999999999999999
#define N 1010
#define M 40040
int u[M],v[M],w[M];
int n,ml,md,el = 0;
void input()
{
	int x,y,xy;
	scanf("%d%d%d",&n,&ml,&md);
	for(int i = 0; i < ml; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		u[el]=x;
		v[el]=y;
		w[el++]=xy;
		/*
		u[el]=y;
		v[el]=x;
		w[el++]=xy;
		*/
	}
	for(int i = ml; i <ml + md; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		/*
		u[el]=x;
		v[el]=y;
		w[el++]=-xy;
		*/
		u[el]=y;
		v[el]=x;
		w[el++]=-xy;
	}
	for(int i = n; i > 1; i--) {
		u[el]=i;
		v[el]=i-1;
		w[el++]=0;
	}
}
long long d[N];
int BF()
{
	for(int i = 1; i <= n; i++)
		d[i] = NIL;
	d[1] = 0;
	bool ok = true;
	for( int i = 0; ok && i < n; i++) {
		ok = false;
		for(int j = 0; j < el; j++)
			if(d[u[j]] + w[j] < d[v[j]]) {
				ok = true;
				d[v[j]] = d[u[j]] + w[j];
			}
	}
	if(d[n] == NIL )
		return -2;
	for(int j = 0; j < el; j++)
		if(d[u[j]] + w[j] < d[v[j]])
			return -1;
	return d[n];
}
int main()
{
	input();
	printf("%d",BF());
}
	