#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1110
#define M 5010
#define NIL 9999999999999
long long u[M*2],v[M*2],w[M*2];
int n,m,ori,des,el;
int edge[N][N];
int len[N][N];
long long plen[N],d[N],path[N];
void DJ()
{
	long long min;
	for(int i = 0; i < n; i++)
		d[i] = plen[i] = NIL;
	d[ori] = plen[ori] = 0;
	el = 0;
	for(int i = 0; i < n;i++) {
		min = NIL;
		for(int j = 0;j < n; j++)
			if(min > edge[i][j])
				min = edge[i][j];
		for(int j = 0; j < n; j++)
			if(edge[i][j] == min && min != NIL)
			{
				u[el]=i;
				v[el] = j;
				w[el++]=min;
			}
	}
	//bool ok = true;
	for(int i = 0;  i < n; i++) {
	//	ok = false;
		for(int j = 0; j < el; j++)
			if(d[u[j]] + w[j] < d[v[j]] || (d[u[j]] + w[j] == d[v[j]] && plen[u[j]] + len[u[j]][v[j]] < plen[v[j]])) {
				d[v[j]] = d[u[j]] + w[j];
				plen[v[j]] = plen[u[j]] + len[u[j]][v[j]];
	//			ok = true;
			}
	}
	for(int j = 0; j < el; j++)
		if(d[u[j]] + w[j] < d[v[j]]) {
			printf("UNBOUND\n");
			return ;
		}
	if(d[des] == NIL)
		printf("VOID\n");
	else
		cout << d[des] << " " << plen[des];
}
/*
bool BF()
{
	for(int i = 1; i <= n; i++)
		d[i] = NIL;
	d[ori] = plen[ori] = 0;
	//bool ok = true;
	for(int i = 0; i < n; i++) {
	//	ok = false;
		for(int j = 0; j < el; j++)
			if(d[u[j]] + w[j] < d[v[j]] ) {
		//		ok = true;
				d[v[j]] = d[u[j]] + w[j];
			}
	}
	for(int j = 0; j < el; j++)
		if(d[u[j]] + w[j] < d[v[j]]) {
			printf("UNBOUND\n");
			return false;
		}
		/*
	while(ori!=des)
	{
		for(int i = 1; i < n;i++)
			if(edge[path[des]][i] < edge[path[des]][des]) {
				printf("VOID\n");
				return false;
			}
			des=path[des];
	}
	return true;
}
*/
bool input()
{
	char c;
	el=0;
	int x,y,xy,l,yx;
	if(scanf("%d%d%d%d",&n,&m,&ori,&des)!=4)
		return false;
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			edge[i][j] = NIL;
	for(int i = 0; i < m;i++) {
		cin >> c;
		scanf("%d,%d,%d[%d]%d)",&x,&y,&xy,&l,&yx);
		if(x==y)
			continue;
		if(edge[x][y] > xy || (edge[x][y] == xy && len[x][y] > l)) {
			edge[x][y] = xy;
			len[x][y] = l;
		}
		if(edge[y][x] > yx || (edge[y][x] == yx && len[y][x] > l)) {
			edge[y][x] = yx;
			len[y][x] = l;
		}
		/*
		u[el] = x;
		v[el] = y;
		w[el++] = xy;
		u[el] = y;
		v[el] = x;
		w[el++] = yx;
		*/
	}
	return true;
}
int main()
{
	while(input())
			//if(BF())
				DJ();
}