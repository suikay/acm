/*
ID: immozer1
PROG: ****
LANG: C++
*/
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
#define N 50
using namespace std;
struct Point {
	int x,y;
};
char m[N][N];
bool v[N][N];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int sx,sy,ex,ey,w,h;
int bfs()
{
	Point st[N*N];
	int top(0),end(0),tx,ty,step[N*N],ttx,tty;
	st[end].x = sx;
	st[end++].y = sy;
	v[sx][sy] = true;
	step[0] = 1;
	while(true) {
		tx = st[top].x;
		ty = st[top].y;
		if(tx == ex && ty == ey)
			return step[top];
		for(int i = 0; i < 4; i++) {
			ttx = tx + dx[i];
			tty = ty + dy[i];
			if(ttx >= h || ttx < 0 || tty >= w || tty < 0)
				continue;
			if(!v[ttx][tty] && m[ttx][tty] != '#') {
				st[end].x = ttx;
				st[end].y = tty;
				v[ttx][tty] = true;
				step[end] = step[top]+1;
				end++;
			}
		}
		top++;
	}
	return 0;
}
int wall(int x,int y,int dir,int ppy)
{
	int tx,ty;
	dir = (dir - ppy + 4) % 4;
	if(x == ex && y == ey)
		return 0;
	for(int i = 0; i < 4; i++) {
		tx = x + dx[dir];
		ty = y + dy[dir];
		if(tx >= 0 && ty >= 0 && tx < h && ty < w && m[tx][ty] != '#')
			return wall(tx,ty,dir,ppy)+1;
		dir = (dir + ppy + 4) % 4;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--) 
	{
		memset(v,false,sizeof(v));
		scanf("%d%d",&w,&h);
		for(int i = 0; i < h; i++)
			scanf("%s",m[i]);
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++) {
				if(m[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				if(m[i][j] == 'E') {
					ex = i;
					ey = j;
				}
			}
		int dir;
		if(sx == 0)
			dir = 0;
		if(sy == 0)
			dir = 3;
		if(sx == h-1)
			dir = 2;
		if(sy == w-1)
			dir = 1;
		printf("%d %d %d\n",wall(sx,sy,dir,1)+1,wall(sx,sy,dir,-1)+1,bfs());
	}
	return 0;
}