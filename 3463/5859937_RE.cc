#include <string.h>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct Node 
{
	int v,d;
	inline bool operator<(const Node &x) const {
		return d > x.d;
	}
};
const int N = 11000;
int head[N],next[N],v[N],w[N],d[N],n,M,s,f,pn,c1[N],c2[N];
void input()
{
	int x,y,z;
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(d,0x3f,sizeof(d));
	scanf("%d%d",&n,&M);
	pn = 1;
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d",&x,&y,&z);
		v[pn] = y; w[pn] = z; next[pn] = head[x]; head[x] = pn++;
	}
	scanf("%d%d",&s,&f);
}
Node heap[N*3];
int dijstra(int s,int f)
{
	int now,vv,ww,hn(0);
	//priority_queue<Node> pq;
	Node tmp;
	heap[0].v = s; heap[0].d = 0; hn = 1;
	//tmp.v = s; tmp.d = 0;
	d[s] = 0;
	//pq.push(tmp);
	while(hn)
	{
		tmp = heap[0];
		pop_heap(heap,heap+hn); hn--;
		//tmp = pq.top(); pq.pop();
		vv = tmp.v; ww = tmp.d;
		if(ww > d[vv]+1)
			continue;
		if(ww < d[vv]) {
			c1[vv] = 1;
			d[vv] = ww;
		} else 
			if(ww == d[vv])
				c1[vv]++;
			else 
				if(ww == d[vv]+1)
					c2[vv]++;
		now = head[vv];
		while(now) {
			//tmp.v = v[now];
			//tmp.d = ww+w[now];
			//pq.push(tmp);
			heap[hn].v = v[now];
			heap[hn].d = ww+w[now];
			hn++;
			push_heap(heap,heap+hn);
			now = next[now];
		}
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
2
5 8
1 2 3
1 3 2
1 4 5
2 3 1
2 5 3
3 4 2
3 5 4
4 5 3
1 5
5 6
2 3 1
3 2 1
3 1 10
4 5 2
5 2 7
5 2 7
4 1
*/
				
