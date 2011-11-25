#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 250;
const int E = 4000;


#define typef int                   // type of flow 
const typef inf = 0x3f3f3f3f;     // max of flow 
typef minf(typef a, typef b) { return a < b ? a : b; } 

struct edge { 
	int u, v; typef cuv, cvu, flow; 
	edge (int x=0, int y=0, typef cu=0, 
		typef cv=0, typef f=0) 
		: u(x), v(y), cuv(cu), cvu(cv), flow(f) {} 
	int other(int p) { return p == u ? v : u; } 
	typef cap(int p) { 
		return p == u ? cuv-flow : cvu+flow; 
	} 
	void  addflow(int  p,  typef  f)  {  flow  +=  (p  ==  u  ?  f  :  -f);  }
}; 

struct vlist { 
	int lv, next[N], idx[2 * N], v; 
	void clear(int cv) { 
		v = cv; lv = -1; 
		memset(idx, -1, sizeof(idx)); 
	} 
	void insert(int n, int h) { 
		next[n] = idx[h]; idx[h] = n; 
		if (lv < h) lv = h; 
	} 
	int remove() { 
		int r = idx[lv];  idx[lv] = next[idx[lv]]; 
		while (lv >= 0 && idx[lv] == -1) lv--; 
		return r; 
	} 
	bool empty() { return lv < 0; } 
}; 

struct network { 
	vector<edge> eg; 
	vector<edge*> net[N]; 
	vlist list; 
	typef e[N]; 
	int v, s, t, h[N], hn[2 * N], cur[N]; 
	void push(int); 
	void relabel(int); 
	void build(int, int, int,int x[N][N],int); 
	typef maxflow(int, int); 
}; 
void network::push(int u) { 
	edge* te = net[u][cur[u]]; 
	typef ex = minf(te->cap(u), e[u]); 
	int p = te->other(u); 
	if (e[p] == 0 && p != t) list.insert(p, h[p]); 
	te->addflow(u, ex); e[u] -= ex; e[p] += ex; 
} 
void network::relabel(int u) { 
	int i, p, mh = 2 * v, oh = h[u]; 
	for (i = net[u].size()-1; i >= 0; i--) { 
		p = net[u][i]->other(u); 
		if (net[u][i]->cap(u) != 0 && mh > h[p] + 1) 
			mh = h[p] + 1; 
	} 
	hn[h[u]]--; hn[mh]++; h[u] = mh; 
	cur[u] = net[u].size()-1; 

	if (hn[oh] != 0 || oh >= v + 1) return; 
	for (i = 0; i < v; i++) 
		if (h[i] > oh && h[i] <= v && i != s) { 
			hn[h[i]]--; hn[v+1]++; h[i] = v + 1; 
		} 
} 
typef network::maxflow(int ss, int tt) { 
	s = ss; t = tt; 
	int i, p, u;  typef ec; 

	for (i = 0; i < v; i++) net[i].clear(); 
	for (i = eg.size()-1; i >= 0; i--) { 
		net[eg[i].u].push_back(&eg[i]); 
		net[eg[i].v].push_back(&eg[i]); 
	} 

	memset(h, 0, sizeof(h)); memset(hn, 0, sizeof(hn)); 
	memset(e, 0, sizeof(e)); e[s] = inf; 
	for (i = 0; i < v; i++) h[i] = v; 
	queue<int> q; q.push(t); h[t] = 0; 
	while (!q.empty()) { 
		p = q.front(); q.pop(); 
		for (i = net[p].size()-1; i >= 0; i--) { 
			u = net[p][i]->other(p); 
			ec = net[p][i]->cap(u); 
			if (ec != 0 && h[u] == v && u != s) { 
				h[u] = h[p] + 1; q.push(u); 
			} 
		} 
	} 
	for (i = 0; i < v; i++) hn[h[i]]++; 

	for (i = 0; i < v; i++) cur[i] = net[i].size()-1; 
	list.clear(v); 
	for (; cur[s] >= 0; cur[s]--) push(s); 

	while (!list.empty()) { 
		for (u = list.remove(); e[u] > 0; ) { 
			if (cur[u] < 0) relabel(u); 
			else if (net[u][cur[u]]->cap(u) > 0 && 
				h[u] == h[net[u][cur[u]]->other(u)]+1) 
				push(u); 
			else cur[u]--; 
		} 
	} 
	return e[t]; 
} 
void network::build(int k,int c,int m,int net[N][N],int up_bound) {
	v = k+c+2; eg.clear(); 
	int a, b, i;  typef l; 
	for(int i = 1; i <= k; i++)
		for(int j = k+1; j < v; j++)
			if(net[i][j] <= up_bound) 
				eg.push_back(edge(i,j,net[i][j],0));
	for(int i = 1; i <= k; i++)
		eg.push_back(edge(0,i,m,0));
	for(int j = k+1; j <= k+c; j++)
		eg.push_back(edge(j,v-1,1,0));
	/*
	for (i = 0; i < m; i++) { 
	cin >> a >> b >> l; 
	eg.push_back(edge(a, b, l, 0)); // vertex: 0 ~ n-1 
	} */
} 

network nt;
int net[N][N];
int main()
{
	int m,k,c,n,tmp;
	scanf("%d%d%d",&k,&c,&m);
	n = k + c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d",&net[i][j]);

	int left,right,mid;
	left = 0; right = 200;
	while(left < right) 
	{
		mid = (left + right)/2;
		nt.build(k,c,m,net,mid);
		if(nt.maxflow(0,n+1) == c)
			right = mid;
		else
			left = mid+1;
		//if(
	}
	printf("%d\n",left);
	return 0;
}