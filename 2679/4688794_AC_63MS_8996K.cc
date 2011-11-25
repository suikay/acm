#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1110
#define M 10010
#define INFINITY 9999999
//分别用u,v,w,l来记录起始点,终点,权值和长度
int u[M],v[M],w[M],l[M];
int n,m,ori,des,el;
//邻接表
int edge[N][N];
int len[N][N];
int plen[N],d[N];
void DJ()
{
	int min;
	for(int i = 0; i < n; i++)
		d[i] = plen[i] = INFINITY;
	d[ori] = plen[ori] = 0;
	el = 0;
	//将所有rewarding的边找出来,放入u,v,w,l中
	for(int i = 0; i < n;i++) {
		min = INFINITY;
		for(int j = 0;j < n; j++)
			if(min > edge[i][j] )
				min = edge[i][j];
		if(min == INFINITY)
			continue;
		for(int j = 0; j < n; j++)
			if(edge[i][j] <= min )
			{
				u[el]=i;
				v[el] = j;
				w[el]=edge[i][j];
				l[el++]=len[i][j];
			}
	}
	//最短路径
	for(int i = 0;  i <= n; i++) {
		for(int j = 0; j < el; j++)
			if(d[u[j]] < INFINITY &&( d[u[j]] + w[j] < d[v[j]] || (d[u[j]] + w[j] == d[v[j]] && (plen[u[j]] + l[j]) < plen[v[j]]))) {
				d[v[j]] = d[u[j]] + w[j];
				plen[v[j]] = plen[u[j]] + l[j];
			}
	}
	int res = d[des];
	/*		找负环,由于负环需要很久才能传递到源点,所以用 d[v[j]]=-999999来加速传递
	如觉得我表述不清请看: 3 3 2 0 (2,0,100[1]0) (1,2,-1[1]100) (1,1,-1[1]0)
	结果应该是:		UNBOUND		*/
	for(int i = 0;  i <= n; i++) {
		for(int j = 0; j < el; j++)
			if(d[u[j]] < INFINITY &&( d[u[j]] + w[j] < d[v[j]] || (d[u[j]] + w[j] == d[v[j]] && (plen[u[j]] + l[j]) < plen[v[j]])))
				d[v[j]] = -9999999;
	}
	if(d[des]  < res) {
		printf("UNBOUND\n");
			return ;
		}
	if(d[des] == INFINITY)
		printf("VOID\n");
	else
		cout << d[des] << " " << plen[des] << endl;
}
bool input()
{
	char c;
	el=0;
	int x,y,xy,ll,yx;
	if(!(cin >> n))
		return false;
	cin >> m >> ori >> des;
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			edge[i][j] = INFINITY;
	for(int i = 0; i < m;i++) {
		cin >> c;
		scanf("%d,%d,%d[%d]%d)",&x,&y,&xy,&ll,&yx);
		//只选权最小的边然后权相同选长度相同的
		if(edge[x][y] > xy || (edge[x][y] == xy && len[x][y] > ll)) {
			edge[x][y] = xy;
			len[x][y] =ll;
		}
		if(edge[y][x] > yx || (edge[y][x] == yx && len[y][x] > ll)) {
			edge[y][x] = yx;
			len[y][x] = ll;
		}
	}
	return true;
}
int main()
{
	while(input())
		DJ();
}