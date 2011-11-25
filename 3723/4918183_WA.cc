#include<algorithm>
using namespace std;
#include<memory.h>
#include<stdio.h>
struct Edge{
	int e,v,w;
	bool operator()(Edge a,Edge b)
	{
		return a.w > b.w;
	}
};
Edge edge[110000];
int parent[22000];
int findp(int x)
{
	if(parent[x] >= 0)
	{
		parent[x] = findp(parent[x]);
		return parent[x];
	}
	return x;
}
void Union(int a,int b)
{
	if(parent[a] < parent[b])
		parent[b] = a;
	else
	{
		if(parent[b] == parent[a])
			parent[b]--;
		parent[a] = b;
	}
}

int f(int r)
{
	int res = 0,p1,p2;
	bool v[22000];
	sort(edge,edge+2*r,Edge());
	memset(parent,-1,sizeof(parent));
	for(int i = 0; i < r; i++)	{
		p1 = findp(edge[i].e);
		p2 = findp(edge[i].v);
		if( p1 != p2 )	{
			res += edge[i].w;
			Union(p1,p2);
		}
	}
	return res;
}

int main()
{
	int c,m,n,r,x,y,d,sum;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d%d",&n,&m,&r);
		sum = 10000*(n + m);
		for(int i = 0; i < r; i++)	{
			scanf("%d%d%d",&x,&y,&d);
			edge[i].e = x;
			edge[i].v = y+n;
			edge[i].w = d;
			/*
			edge[i+r].e = y+n;
			edge[i+r].v = x;
			edge[i+r].w = d;
			*/
		}
		printf("%d\n",sum-f(r));
	}
	return 0;
}