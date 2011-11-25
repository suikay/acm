#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
#define N 30
struct Edge
{
	int u,v,w;
	bool operator<(const Edge &e) const {
		if(w != e.w)
			return w < e.w;
		else
			return (u < e.u || ((u == e.u) && (v < e.v)));
	}
};
Edge e[N*N];
int en;
int parent[N];
void init()
{
	en = 0;
	memset(parent,-1,sizeof(parent));

}

int getParent(int x)
{
	if(parent[x] >= 0)
		return parent[x] = getParent(parent[x]);
	return x;
}


int SetMerge(int x,int y)
{
	static int xx,yy;
	xx = getParent(x);
	yy = getParent(y);
	if(xx != yy)
	{
		if(parent[xx] < parent[yy])
			parent[yy] = xx;
		else if(parent[yy] < parent[xx])
			parent[xx] = yy;
		else {
			parent[yy] = xx;
			parent[xx]--;
		}
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n,cnt,dis,res;
	char ori,dst;
	while(scanf("%d",&n) && n)
	{
		init();
		res = 0;
		for(int j = 1; j < n; j++)
		{
			do {
				ori = getchar();
			} while(!(ori >= 'A' && ori <= 'Z'));
			scanf("%d",&cnt);
			ori -= 'A';
			for(int i = 0; i < cnt; i++) 
			{
				do {
					dst = getchar();
				} while(!(dst >= 'A' && dst <= 'Z'));
				scanf("%d",&dis);
				dst -= 'A';
				e[en].u = ori;
				e[en].v = dst;
				e[en++].w = dis;
			}
		}
		sort(e,e+en);
		cnt = 1;
		for(int i = 0; (i < en) && (cnt < n); i++)
			if(SetMerge(e[i].u,e[i].v)) {
				cnt++;
				res += e[i].w;
			}
		printf("%d\n",res);
	}

	return 0;
}
