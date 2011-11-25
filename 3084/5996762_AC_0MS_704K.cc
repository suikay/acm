#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue>
#include <stack> 
#include <bitset>
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>

using namespace std;



const int N = 30;
const int INF = 1000000;
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
	void build(int, int,int x[N][N],bool intr[N]); 
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
void network::build(int m,int sr,int con[N][N],bool intr[N]) { 
	v = 2+m; eg.clear(); 
	int a, b, i, j;  typef l; 
	for (i = 1; i <= m; i++) { 
		if(intr[i])
			eg.push_back(edge(0,i,INF,0));
		for(int j = 1; j <= m; j++)
			if(i != j) {
				if(con[j][i])
					eg.push_back(edge(i,j,INF,0));
				else if(con[i][j])
					eg.push_back(edge(i,j,con[i][j],0));
			}
	}
	eg.push_back(edge(sr,m+1,inf,0));
} 

network nw;
int con[N][N];
bool intr[N];
int main()
{
	int t,m,sr,tmp,cnt,v;
	char ch[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&sr);
		memset(con,0,sizeof(con));
		memset(intr,false,sizeof(intr));
		for(int i = 1; i <= m; i++) {
			scanf("%s",&ch);
			if(ch[1] == '\0')
				intr[i] = true;
			scanf("%d",&cnt);
			for(int j = 0; j < cnt; j++) {
				scanf("%d",&v);
				v++;
				con[v][i]++;
			}
		}
		nw.build(m,sr+1,con,intr);
		tmp = nw.maxflow(0,m+1);
		if(tmp >= INF) 
			puts("PANIC ROOM BREACH");
		else
			printf("%d\n",tmp);
	}

	return 0;
}
/*
3
2 1
I 0
NI 1 0

4 3
I 0
NI 1 2
NI 0
NI 4 1 1 2 2
*/
