#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;
#define N 101
#define M 101
int n,m;
int u[M],v[M],w[M];
bool BF()
{
	int d[N];
	memset(d,0,sizeof(d));
	bool ok=true;
	for(int i = 0; ok && i < n; i++) {
		ok = false;
		for(int j = 0; j < m; j++)
			if(d[u[j]]+w[j]<d[v[j]]) {
				d[v[j]]=d[u[j]]+w[j];
				ok = true;
			}
	}
	for(int j = 0; j < m; j++)
		if(d[u[j]]+w[j]<d[v[j]])
			return false;
	return true;
}
void input()
{
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		char ch[3];
		int x,y,xy;
		for(int i = 0; i < m; i++) {
			cin >> x >> y >> ch >> xy;
			if(ch[0] == 'g') {
				u[i] = y;
				v[i] = x-1;
				w[i] = -(xy+1);
			}
			else {
				u[i] = x-1;
				v[i] = y;
				w[i] = xy-1;
			}
		}
		printf("%s",BF()?"lamentable kingdom\n":"successful conspiracy\n");
	}
}

int main()
{
	input();
}