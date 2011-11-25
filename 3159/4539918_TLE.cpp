#include <stdio.h>
#include <iostream>
#include <memory.h>
#define N 30010
#define M 150010
#define NIL 99999999
int u[M];
int v[M];
int w[M];
int d[N];
int n,m;
void input()
{
	int x,y,xy;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		u[i] = x;
		v[i] = y;
		w[i] = xy;
	}
}
int BF(int ori,int des)
{
	//memset(d,-1,sizeof(d));
	for(int i = 1; i <=n;i++)
		d[i]=NIL;
	d[ori] = 0;
	bool ok=true;
	for(int i = 0;ok && i < n; i++) {
		ok = false;
		for(int j = 0;j < m; j++)
			if( d[u[j]] + w[j] < d[v[j]]) {
				ok = true;
				d[v[j]] = d[u[j]] + w[j];
			}
	}
	return d[des] - d[ori];
}
int main()
{
	/*
	int time;
	scanf("%d",&time);
	while(time--) {
	*/
		input();
		//int a,b;
		//a = BF(1,n);
		//b = BF(n,1);
		printf("%d\n",BF(1,n));
	//}
	return 0;
}
