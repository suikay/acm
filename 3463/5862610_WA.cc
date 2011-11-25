#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 11000;
int d[N];
struct Node
{
	int u,v,dis,ori;
	inline bool operator<(const Node &x) const {
		if(dis == x.dis)
			return ori > x.ori;
		return dis > x.dis;
	}
};
int head[N],next[N],v[N],w[N],c1[N],c2[N];
int n,M,s,f,pn;
void input()
{
	int x,y,z;
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(d,0x6f,sizeof(d));
	scanf("%d%d",&n,&M);
	pn = 1;
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d",&x,&y,&z);
		v[pn] = y; w[pn] = z; next[pn] = head[x]; head[x] = pn++;
	}
	scanf("%d%d",&s,&f);
}

Node heap[200*N];
int dijstra(int s,int f)
{
	int now,vv,ww,hn,uu;
	Node tmp;
	heap[0].u = 0; heap[0].v = s; heap[0].dis = 0; hn = 1;
	c1[0] = 1; c2[0] = 0;
	make_heap(heap,heap+hn);
	while(hn)
	{
		tmp = heap[0];
		pop_heap(heap,heap+hn); hn--;
		uu = tmp.u; vv = tmp.v; ww = tmp.dis;
		if(ww > d[vv]+1)
			continue;
		if(ww < d[vv]) {
			c1[vv] = c1[uu]; c2[vv] = c2[uu];
			d[vv] = ww;
			now = head[vv];
			while(now) {
				heap[hn].u = tmp.v;
				heap[hn].v = v[now];
				heap[hn].dis = ww+w[now];
				heap[hn].ori = d[heap[hn].v];
				hn++;
				push_heap(heap,heap+hn);
				now = next[now];
			}
		} else
			if(ww == d[vv]) {
				c1[vv] += c1[uu];
				c2[vv] += c2[uu];
			}
			else
				if(ww == d[vv]+1)
					c2[vv] += c1[uu];
	}
	return c1[f]+c2[f];
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--) {
		input();
		printf("%d\n",dijstra(s,f));
	}
	return 0;
}
/*
1
3 4
1 2 1
1 3 2
2 3 1
1 2 2
1 3
*/