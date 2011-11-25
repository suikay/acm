#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
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
#define typec int                   // type of res 
const typec inf = 0x3f3f3f3f;     // max of res 
const typec maxw = 1000;           // maximum edge weight 
const int V = 600;
typec g[V][V], w[V]; 
int a[V], v[V], na[V]; 
typec mincut(int n){ 
    int i, j, pv, zj; 
    typec best = maxw * n * n; 
    for (i = 0; i < n; i++) v[i] = i; // vertex: 0 ~ n-1 
    while (n > 1) { 
        for (a[v[0]] = 1, i = 1; i < n; i++) { 
            a[v[i]] = 0; na[i - 1] = i; 
            w[i] = g[v[0]][v[i]]; 
        } 
        for (pv = v[0], i = 1; i < n; i++ ) { 
            for (zj = -1, j = 1; j < n; j++ ) 
                if (!a[v[j]] && (zj < 0 || w[j] > w[zj])) 
					zj = j; 
			a[v[zj]] = 1; 
			if (i == n - 1) { 
				if (best > w[zj]) best = w[zj]; 
				for (i = 0; i < n; i++) 
					g[v[i]][pv] = g[pv][v[i]] += g[v[zj]][v[i]]; 
				v[zj] = v[--n]; 
				break; 
			} 
			pv = v[zj]; 
			for (j = 1; j < n; j++) if(!a[v[j]]) 
				w[j] += g[v[zj]][v[j]]; 
		} 
	} 
    return best; 
} 
int m,n;
bool input()
{
	int u,v,w;
	if(scanf("%d%d",&n,&m) != 2)
		return false;
	memset(g,0,sizeof(g));
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] += w;
		g[v][u] += w;
	}
	return true;
}
int main()
{
	while(input())
		printf("%d\n",mincut(n));
	return 0;
}


