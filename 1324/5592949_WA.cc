#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 5000000;
struct Snake
{
	short hx,hy,status;
	friend bool operator<(const Snake &x,const Snake &y) {
		return memcmp(&x,&y,sizeof(Snake)) < 0;
	}
};
map<Snake,bool> check;
int dirx[]= {0,-1,0,1},diry[] = {1,0,-1,0};
bool v[25][25];
int clean,want,m,n,l,res;
short ch[700000] = {0};
bool body_check(short pp)
{
	unsigned short tmp,p = pp;
	tmp = p;
	if(ch[p])
		return ch[p] == 1;
	short x,y;
	x = y = 0;
	for(int i = 0; i < l; i++) {
		x += dirx[p&3];
		y += diry[p&3];
		if(x == 0 && y == 0)
			return (ch[tmp] = -1)==1;
		p >>= 2;
	}
	return (ch[tmp] = 1)==1;
}

int dir(int x,int y)
{
	if(y == 1)
		return 2;
	if(y == -1)
		return 0;
	if(x == 1)
		return 1;
	return 3;
}
Snake st[N];
int step[N];
int bfs(Snake& snake)
{
	short hx,hy,lx,ly,hs,steps,xx,yy;
	Snake tmp;
	int top,end;
	top = end = 0;
	step[end] = 0;
	st[end++] = snake;
	check[snake] = true;
	while(top < end)
	{
		hx = st[top].hx;
		hy = st[top].hy;
		hs = st[top].status;
		for(int i = 0; i < 4; i++) {
			xx = dirx[i] + hx;
			yy = diry[i] + hy;
			if(xx < 1 || yy < 1 || xx > n || yy > m ||
				v[xx][yy])
				continue;
			tmp.hx = xx;
			tmp.hy = yy;
			tmp.status = (hs >> 2) | (i << (2*(l-2)));
			if(!body_check(hs | (i << (2*(l-1)))) || check.count(tmp))
				continue;
			if(xx == 1 && yy == 1)
				return step[top]+1;
			st[end] = tmp;
			step[end] = step[top] + 1;
			end = (end+1)%N;
		}
		top = (top + 1) % N;
	}
	return -1;
}
int main()
{
	Snake ori;
	int b,k,lastx,lasty,nowx,nowy;
	k = 1; 
	while(true)
	{
		memset(v,false,sizeof(v));
		check.clear();
		res = 0x7fffffff;
		scanf("%d%d%d",&n,&m,&l);
		if(n == 0)
			return 0;
		scanf("%d%d",&(ori.hx),&(ori.hy));
		lastx = ori.hx ;
		lasty = ori.hy;
		ori.status = 0;
		for(int i = 1; i < l; i++) {
			scanf("%d%d",&nowx,&nowy);
			ori.status = (ori.status << 2) + dir(nowx-lastx,nowy-lasty);
			lastx = nowx;
			lasty = nowy;
		}
		scanf("%d",&b);
		for(int i = 0; i < b; i++) {
			scanf("%d%d",&nowx,&nowy);
			v[nowx][nowy] = true;
		}
		cout << "Case " << k++ << ": " << bfs(ori) << endl;
	}

	return 0;
}
/*
5 6 4
4 1
4 2
3 2
2 2
3
2 3
3 3
3 4
*/