#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1110
#define M 5010
#define NIL 9999999999999
#define INFINITY 99999999
long long u[M*2],v[M*2],w[M*2];
int n,m,ori,des,el;
int edge[N][N];
int len[N][N];
long long plen[N],d[N],path[N];
void DJ()
{
	int min;
	for(int i = 0; i < n; i++)
		d[i] = plen[i] = NIL;
	d[ori] = plen[ori] = 0;
	el = 0;
	for(int i = 0; i < n;i++) {
		min = INFINITY;
		for(int j = 0;j < n; j++)
			if(min > edge[i][j])
				min = edge[i][j];
		if(min == INFINITY)
			continue;
		for(int j = 0; j < n; j++)
			if(edge[i][j] == min && min != NIL)
			{
				u[el]=i;
				v[el] = j;
				w[el++]=min;
			}
	}
	for(int i = 0;  i < n; i++) {
		for(int j = 0; j < el; j++)
			if(d[u[j]] < NIL &&( d[u[j]] + w[j] < d[v[j]] || (d[u[j]] + w[j] == d[v[j]] && plen[u[j]] + len[u[j]][v[j]] < plen[v[j]]))) {
				d[v[j]] = d[u[j]] + w[j];
				plen[v[j]] = plen[u[j]] + len[u[j]][v[j]];
			}
	}
	long long res = d[des];
	for(int i = 0;  i < n; i++) {
		for(int j = 0; j < el; j++)
			if(d[u[j]] < NIL && (d[u[j]] + w[j] < d[v[j]] || (d[u[j]] + w[j] == d[v[j]] && plen[u[j]] + len[u[j]][v[j]] < plen[v[j]]))) {
				d[v[j]] = d[u[j]] + w[j];
				plen[v[j]] = plen[u[j]] + len[u[j]][v[j]];
			}
	}
	if(d[des]  < res) {
		printf("UNBOUND\n");
			return ;
		}
	if(d[des] == NIL)
		printf("VOID\n");
	else
		cout << d[des] << " " << plen[des] << endl;
}
bool input()
{
	char c;
	el=0;
	int x,y,xy,l,yx;
	if(scanf("%d%d%d%d",&n,&m,&ori,&des)!=4)
		return false;
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			edge[i][j] = INFINITY;
	for(int i = 0; i < m;i++) {
		cin >> c;
		scanf("%d,%d,%d[%d]%d)",&x,&y,&xy,&l,&yx);
		if(edge[x][y] > xy || (edge[x][y] == xy && len[x][y] > l)) {
			edge[x][y] = xy;
			len[x][y] = l;
		}
		if(edge[y][x] > yx || (edge[y][x] == yx && len[y][x] > l)) {
			edge[y][x] = yx;
			len[y][x] = l;
		}
	}
	return true;
}
int main()
{
	while(input())
				DJ();
}
/*
3 3 0 2 (0,1,0[1]0) (0,2,1[1]0) (1,2,1[1]0)
3 3 2 0 (0,1,-1[1]1) (0,2,0[1]0) (1,2,0[1]1)
7 11 0 5 (0,1,-1[6]4) (0,2,-1[5]4) (0,3,0[1]0)  (1,4,3[10]1)
(2,4,3[10]1) (3,4,0[5]0)  (3,5,0[30]0) (3,5,1[20]0)
 (4,6,0[3]1)  (6,5,1[8]0)  (6,6,0[2]-1)
 */