#include <stdio.h>
#include <memory.h>
#define MAX_NODE 501
#define INFINITY 999999999
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int weight;
}ArcNode;
typedef struct VNode{
	ArcNode *firstarc;
}VNode;
VNode *AdjList;
bool BF(int n,int s)
{
	bool in[MAX_NODE];
	int count[MAX_NODE];
	ArcNode *p;
	memset(in,false,MAX_NODE*sizeof(bool));
	int Queue[MAX_NODE],d[MAX_NODE];
	for(int i = 1; i <= n; i++) {
		d[i] = INFINITY;
		count[i] = 0;
	}
	int point = 0,u,v;
	Queue[point++] = s;
	in[s] = true;
	d[s] = 0;
	while( point > 0)
	{
		u = Queue[--point];
		in[u] = false;
		count[u]++;
		if(count[u] > n)
			return false;
		p = AdjList[u].firstarc;
		while(p) {
			v = p->adjvex;
			if(d[u] + p->weight < d[v]) {
				if(!in[v]) {
					Queue[point++] = v;
					in[v] = true;
				}
				d[v] = d[u] + p->weight;
			}
			p = p->nextarc;
		}
	}
	return true;
}
int main()
{
	int n,m,w,time;
	int x,y,xy;
	ArcNode *p;
	scanf("%d",&time);
	while(time--) {
		scanf("%d%d%d",&n,&m,&w);
		AdjList = new VNode[n+1];
		AdjList[0].firstarc  = NULL;
		for(int i = 1; i <= n; i++) {
			p = new ArcNode;
			p->weight = 0;
			p->adjvex = i;
			p->nextarc = AdjList[0].firstarc;
			AdjList[0].firstarc = p;
			AdjList[i].firstarc = NULL;
		}
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d",&x,&y,&xy);
			p = new ArcNode;
			p->adjvex = y;
			p->weight = xy;
			p->nextarc = AdjList[x].firstarc;
			AdjList[x].firstarc = p;
			p = new ArcNode;
			p->adjvex = x;
			p->weight = xy;
			p->nextarc = AdjList[y].firstarc;
			AdjList[y].firstarc = p;
		}
		for(int i = 0; i < w; i++) {
			scanf("%d%d%d",&x,&y,&xy);
			p = new ArcNode;
			p->adjvex = y;
			p->weight = -xy;
			p->nextarc = AdjList[x].firstarc;
			AdjList[x].firstarc = p;
		}
		if(!BF(n,0))
			printf("Yes\n");
		else
			printf("No\n");
	}
		return 0;
}