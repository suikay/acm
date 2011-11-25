#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define CLEAN(A,B) memset((A),(B),sizeof((A)))
const int N = 100010;
int head[N],next[N*2],v[N*2];
unsigned long long w[N*2],dis[N],weight[N];
bool visited[N];
struct Node
{
	int v;
	unsigned long long dis;
	inline bool operator<(const Node &x) const {
		return dis > x.dis;
	}
};
Node node[2*N],heap[2*N];
int main()
{
	int E,V,C;
	int pn,hn;
	int x,y,now,vv,cnt;
	unsigned long long res,z,ww;
	scanf("%d",&C);
	while(C--) 
	{
		scanf("%d%d",&V,&E);
		CLEAN(head,0); CLEAN(next,0); CLEAN(dis,0xff); CLEAN(visited,false);
		for(int i = 1; i <= V; i++)
			scanf("%llu",&weight[i]);
		pn = hn = 0;
		for(int i = 1; i <= E; i++) {
			scanf("%d%d%llu",&x,&y,&z);
			v[pn] = x; next[pn] = head[y]; w[pn] = z; head[y] = pn++;
			v[pn] = y; next[pn] = head[x]; w[pn] = z; head[x] = pn++;
		}
		if(V == 1) {
			puts("0");
			continue;
		}
		if(E < V-1) {
			puts("No Answer");
			continue;
		}
		now = head[1];
		visited[1] = true;
		dis[1] = 0;
		while(now) {
			dis[v[now]] = w[now];
			heap[hn].dis = w[now];
			heap[hn].v = v[now];
			hn++;
			now = next[now];
		}
		make_heap(heap,heap+hn);
		cnt = 1;
		res = 0;
		while(hn) {
			vv = heap[0].v; ww = heap[0].dis;
			pop_heap(heap,heap+hn);
			hn--;
			if(visited[vv])
				continue;
			dis[vv] = ww;
			res += ww*weight[vv];
			visited[vv] = true;
			if((++cnt) == V)
				break;
			now = head[vv];
			while(now) {
				if(!visited[v[now]] && dis[v[now]] > w[now]+ww) {
					dis[v[now]] = w[now]+ww;
					heap[hn].dis = w[now]+ww;
					heap[hn].v = v[now];
					hn++;
					push_heap(heap,heap+hn);
				}
				now = next[now];
			}
		}
		if(cnt == V) {
			printf("%I64u\n",res);
		} else
			puts("No Answer");
	}

	return 0;
}

/*
1
7 7
1000 10 20 30 40 50 60
1 2 1
2 3 3
2 4 2
3 5 4
3 7 2
3 6 3
1 5 9
*/