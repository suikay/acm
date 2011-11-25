#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Snake
{
	unsigned short x,y,body;
	Snake(unsigned short xx,unsigned short yy,unsigned short bb):x(xx),y(yy),body(bb) {}
	Snake(){}
};
const int N = 1000000;
int dirx[] = {0,-1,0,1},diry[] = {1,0,-1,0};
bool valid[70000],visited[450][66000],stone[25][25];
Snake ori,st[N];
int step[N];
int n,m,l;

int dir(int x,int y)
{
	if(y == -1)
		return 0;
	if(x == -1)
		return 3;
	if(y == 1)
		return 2;
	return 1;
}

bool invalid(unsigned short body)
{
	static short d[10],x,y;
	static unsigned short p;
	if(valid[body])
		return (valid[body]==-1);
	p = body;
	for(int i = 0; i < l; i++) {
		d[i] = ((p&3)+2)&3;
		p >>= 2;
	}
	x = 0;
	y = 0;
	for(int i = l-1; i >= 0; i--)
	{
		x += dirx[d[i]];
		y += diry[d[i]];
		if(x == 0 && y == 0) {
			valid[body] = -1;
			return true;
		}
	}
	valid[body] = 1;
	return false;
}

int bfs()
{
	int top,end,now;
	short x,y,b,xx,yy,bb;
	top = end = 0;
	st[end] = ori;
	step[end++] = 0;
	visited[ori.x*21+ori.y][ori.body] = true;
	while(top < end)
	{
		x = st[top].x;
		y = st[top].y;
		b = st[top].body;
		for(int i = 0; i < 4; i++) {
			xx = x + dirx[i];
			yy = y + diry[i];
			bb = (b >> 2) | (i << 2*(l-2));
			if(xx < 1 || yy < 1 || xx > m || yy > n || stone[xx][yy]
				|| visited[xx*21+yy][bb] || invalid(b | (bb << 2)))
				continue;
			if(xx == 1 && yy == 1)
				return step[top]+1;
			visited[xx*21+yy][bb] = true;
			step[end] = step[top] + 1;
			st[end].x = xx;
			st[end].y = yy;
			st[end++].body = bb;
		}
		top++;
	}
	return -1;
}

bool input()
{
	int lastx,lasty,nowx,nowy,body,k;

	memset(visited,false,sizeof(visited));
	memset(valid,false,sizeof(valid));
	memset(stone,false,sizeof(stone));
	scanf("%d%d%d",&m,&n,&l);
	if(!m && !n && !l)
		return false;
	scanf("%d%d",&(ori.x),&(ori.y));
	lastx = ori.x;
	lasty = ori.y;
	body = 0;
	for(int i = 1; i < l; i++) {
		scanf("%d%d",&nowx,&nowy);
		body = (body << 2) | dir(nowx-lastx,nowy-lasty);
		lastx = nowx;
		lasty = nowy;
	}
	ori.body = body;
	scanf("%d",&k);
	for(int i = 0; i < k; i++) {
		scanf("%d%d",&nowx,&nowy);
		stone[nowx][nowy] = true;
	}

	return true;
}

int main()
{
	int k(1);
	while(input())
		printf("Case %d: %d\n",k++,bfs());

	return 0;
}
/*
5 6 4
4 1
4 2
3 2
3 1
3
2 3
3 3
3 4

4 4 4
2 3
1 3
1 4
2 4
4

2 1
2 2
3 4
4 2

0 0 0
*/