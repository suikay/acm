#include <stdio.h>
#include <iostream>
#include <memory.h>
#define N 30010
#define M 150010
#define NIL 99999999
int next[M];
int v[M];
int w[M];
int first[N];
int d[N];
int n,m;
void input()
{
	int i,x,y,xy;
	scanf("%d%d",&n,&m);
	for(i = 1; i <= m; i++) {
		scanf("%d%d%d",&x,&y,&xy);
		next[i] = first[x];
		v[i] = y;
		w[i] = xy;
		first[x] = i;
	}
}
int BF()
{
	for(int i = 1; i <=n;i++)
		d[i]=NIL;
	bool in[N];
	int stack[N],top=0,a,p;
	memset(in,false,sizeof(in));
	d[1] = 0;
	stack[top++]=1;
	in[1]=true;
	while(top){
		a=stack[--top];
		in[a]=false;
		p=first[a];
		while(p) {
			if( d[a] + w[p] < d[v[p]]) {
				d[v[p]] = d[a] + w[p];
				if(!in[v[p]]) {
					in[v[p]]=true;
					stack[top++]=v[p];
				}
			}
			p=next[p];
		}
	}
	return d[n];
}
int main()
{
		input();
		printf("%d\n",BF());
	return 0;
}
