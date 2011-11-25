#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct Tank
{
	int g,x,y;
	Tank(){}
	Tank(int xx,int yy,int gg) {
		x = xx; y = yy; g = gg;
	}
	bool operator<(const Tank &t) const{
		return g > t.g;
	}
};
int dirx[]={0,0,1,-1},diry[]={1,-1,0,0};
int m,n,ox,oy,dx,dy;
const int N = 310;
char b[N][N];
int v[N][N];
priority_queue<Tank> pt;

int mht(int x,int y)
{
	return abs(x-dx)+abs(y-dy);
}
int astar()
{
	Tank now;
	int xx,yy,gg,x,y,g;
	pt.push(Tank(ox,oy,0));
	v[ox][oy] = true;
	while(!pt.empty())
	{
		now = pt.top();
		pt.pop();
		xx = now.x;
		yy = now.y;
		gg = now.g;
		for(int i = 0; i < 4; i++) {
			x = xx+dirx[i]; y = yy+diry[i];
			if(x == dx && y == dy) 
				return gg+1;
			if(x < 0 || y < 0 || x >= m || y >= n || 
				b[x][y] == 'S' || b[x][y] == 'R')
				continue;
			g = (b[x][y]=='B')?(gg+2):(gg+1);
			if(g >= v[x][y])
				continue;
			v[x][y] = g;
			pt.push(Tank(x,y,g));
		}
	}
	return -1;
}
	
int main()
{
	while(true)
	{
		while(!pt.empty())
			pt.pop();
		memset(v,0x7f,sizeof(v));
		scanf("%d%d",&m,&n);
		getchar();
		if(!m && !n)
			return 0;
		for(int i = 0; i < m; i++) {
			gets(b[i]);
			for(int j = 0; j < n ;j++)
				if(b[i][j] == 'Y') {
					ox = i;
					oy = j;
				} else if(b[i][j] == 'T') {
					dx = i;
					dy = j;
				}
		}
		printf("%d\n",astar());
	}

	return 0;
}