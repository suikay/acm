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
	void build(int n,int scr[N],bool net[N][N],bool valid[N]); 
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
void network::build(int n,int scr[N],bool net[N][N],bool valid[N]) { 
	v = 2*n+2; eg.clear(); 
	int a, b, i;  typef l; 
	for(int i = 1; i <= n; i++)
		eg.push_back(edge(0,i,n-1-scr[i],0));
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(net[j][i])
				eg.push_back(edge(j,i+n,1,0));
	for(int i = 1; i <= n; i++)
		if(valid[i]) 
			eg.push_back(edge(n+i,v-1,scr[i],0));
} 

int scr[N],high[N];
bool net[N][N],valid[N];
network nw;
int main()
{
	int m,pos,sum,res,a,b,c;
	char num[100];
	scanf("%d",&m);
	gets(num);
	while(m--)
	{
		memset(net,false,sizeof(net));
		memset(valid,false,sizeof(valid));
		memset(high,0,sizeof(high));
		gets(num);
		stringstream ss(num);
		pos = 0;
		while(ss >> scr[++pos]);
		--pos;
		for(int i = 1; i <= pos; i++)
			for(int j = i+1; j <= pos; j++)
				if(scr[i] < scr[j]) {
					net[j][i] = true;
					high[i]++;
				}
		res = sum = 0;
		for(int i = pos; i; i--)
			if(high[i] == 0)
				res++;
			else {
				a = b = c = 0;
				for(int j = 1; j <= pos; j++)
					if(j < i) a++;
					else if(scr[j] < scr[pos]) b++;
					else c++;
				if(a*c+(pos-scr[pos]-1-b)*c < scr[pos]*c)
					break;
				valid[i] = true;
				sum += high[i];
				nw.build(pos,scr,net,valid);
				if(nw.maxflow(0,2*pos+1) != sum)
					break;
				res++;
			}
		printf("%d\n",res);
	}
	return 0;
}
