/* 这题我是用差分约束做的
	求的是最短路,如果有负环
	则 inreliable
*/
#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;
#define NIL 100000000
#define N 1001
#define M 200010
int u[M],v[M],w[M];
int m,n,el;
bool input()
{
	char c;
	el = 0;
	if(!(cin >> n >> m))
		return false;
	for(int i = 0; i < m; i++) {
		cin >> c;
		// P x y l 这种情况将 x -> y 权为 l 加入边数组
		//	同时将 y -> x 权为 -l 加入边数组
		if(c == 'P')	{
			scanf("%d%d%d",&u[el],&v[el],&w[el]);
			u[el+1] = v[el];
			v[el+1] = u[el];
			w[el+1] = -w[el];
			el+=2;
		}
		else {
			//如果 V x y 则将 x -> y 权为 -1 加入边数组
			scanf("%d%d",&v[el],&u[el]);
			w[el++] = -1;
		}
	}
	return true;
}
bool BF()
{
	int d[N];
	for(int i=1; i <= n; i++)
		d[i] = NIL;
	d[1] = 0;
	bool ok = true;
	for(int i = 0; ok && i <= n; i++) {
		ok = false;
		for(int j = 0 ;j < el; j++)
			if(d[u[j]] + w[j] < d[v[j]] )	{
				d[v[j]] = d[u[j]] + w[j];
				//当i == n 的时候还能松弛的情况
				ok = true;
				if(i == n)
					return false;
			}
	}
	return true;
}
int main()
{
	while(input())
		printf("%s\n",BF()?"Reliable":"Unreliable");
}