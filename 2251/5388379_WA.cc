#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
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
#define N 35
struct Point {
	int p,x,y,step;
};
Point st[N*N*N];
int dl[] = {0,0,0,0,1,-1};
int dr[] = {1,-1,0,0,0,0};
int dc[] = {0,0,-1,1,0,0};
int L,R,C,res;
bool v[N][N][N];
char m[N][N][N];
void dfs(int l,int r,int c)
{
	int top,end,tl,tr,tc,ttl,ttr,ttc;
	top = end = 0;
	v[l][r][c] = true;
	st[end].p = l;
	st[end].x = r;
	st[end].y = c;
	st[end++].step = 0;
	while(top < end) {
		tl = st[top].p;
		tr = st[top].x;
		tc = st[top].y;
		for(int i = 0; i < 8; i++) {
			ttl = dl[i] + tl;
			ttr = dr[i] + tr;
			ttc = dc[i] + tc;
			if(ttl >= 0 && ttl < L && ttr >= 0 && ttr < R
				&& ttc >= 0 && ttc < C 
				&& m[ttl][ttr][ttc] != '#'
				&& !v[ttl][ttr][ttc]) {
					v[ttl][ttr][ttc] = true;
					st[end].p = ttl;
					st[end].x = ttr;
					st[end].y = ttc;
					st[end].step = st[top].step+1;
					if(m[ttl][ttr][ttc] == 'E') {
						res = st[end].step;
						return;
					}
					end++;
			}
		}
		top++;
	}
}
int main()
{
	int sl,sr,sc;
	while(scanf("%d%d%d",&L,&R,&C))
	{
		if(!L && !R && !C)
			return 0;
		res = -1;
		memset(v,false,sizeof(v));
		memset(st,0,sizeof(st));
		for(int i = 0; i < L; i++)
			for(int j = 0; j < R; j++) {
				cin >> m[i][j];
				for(int k = 0; k < C; k++)
					if(m[i][j][k] == 'S') {
						sl = i;
						sr = j;
						sc = k;
					}
			}
		dfs(sl,sr,sc);
		if(res != -1)
			printf("Escaped in %d minute(s).\n",res);
		else
			printf("Trapped!\n");
	}
	return 0;
}