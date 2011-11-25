#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct Edge{
	int v,u;
	int w;
	bool operator()(Edge a,Edge b) {
		return a.w > b.w;
	}
};
Edge e[50000];
int parent[1100];
int par(int x)
{
	if(parent[x] == -1)
		return x;
	parent[x] = par(parent[x]);
	return parent[x];
}
void Join(int x,int y)
{
	int tx(par(x)),ty(par(y));
	if(tx == ty)
		return;
	parent[tx] = ty;
}
			
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[M+i].u = e[i].v;
		e[M+i].v = e[i].u;
		e[M+i].w = e[i].w;
	}
	bool v[1100];
	memset(v,false,sizeof(v));
	memset(parent,-1,sizeof(parent));
	v[0] = true;
	sort(e,e+2*M,Edge());
	int _count(1),sum(0);
	for(int i = 0;_count < N; i++) 
		if(par(e[i].u) != par(e[i].v)) {
			Join(e[i].u,e[i].v);
			sum += e[i].w;
			_count++;
		}
	if(_count == N)
		cout << sum << endl;
	else
		cout << -1 << endl;
	return 0;
}