#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;
#define NIL 99999999
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
		std::cin >> c;
		if(c == 'P')	{
			scanf("%d%d%d",&u[el],&v[el],&w[el]);
			u[el+1] = v[el];
			v[el+1] = u[el];
			w[el+1] = -w[el];
			el+=2;
		}
		else {
			scanf("%d%d",&u[el],&v[el]);
			w[el++] = -1;
		}
	}
	return true;
}
bool BF()
{
	int d[N];
	memset(d,0x7f,sizeof(d));
	d[1] = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0 ;j < el; j++)
			if(d[u[j]] + w[j] < d[v[j]] )	{
				d[v[j]] = d[u[j]] + w[j];
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