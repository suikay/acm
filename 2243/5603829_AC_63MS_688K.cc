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
int dirx[]={1,1,2,2,-1,-1,-2,-2},diry[]={-2,2,-1,1,2,-2,1,-1};
int desx,desy;
int v[10][10];

struct Knight
{
	int x,y,g,h;
	bool operator<(const Knight &x) const{
		return (this->g+this->h) > (x.g+x.h);
	}
};
priority_queue<Knight> open;
bool in(const Knight& k)
{
	if(k.x < 1 || k.y < 1 || k.x > 8 || k.y > 8 || v[k.x][k.y] <= k.h)
		return false;
	else
		return true;
}

int mht(Knight& k)
{
	return abs(desx-k.x)+abs(desy-k.y);
}

int astar(const Knight &k)
{
	static Knight now,tmp;
	int x,y,g,gg,xx,yy;
	open.push(k);
	if(k.x == desx && k.y == desy)
		return 0;
	while(!open.empty())
	{
		now = open.top();
		open.pop();
		x = now.x; y = now.y; g = now.g;
		gg = g + 3;
		for(int i = 0; i < 8; i++) {
			tmp.x = x+dirx[i]; tmp.y = y+diry[i]; 
			if(tmp.x == desx && tmp.y == desy)
				return gg/3;
			if(!in(tmp))
				continue;
			v[tmp.x][tmp.y] = gg;
			tmp.h = mht(tmp);
			tmp.g = gg;
			open.push(tmp);
		}
	}
}

int main()
{
	char p[6];
	Knight ori;
	while(gets(p))
	{
		while(!open.empty())
			open.pop();
		memset(v,0x7f,sizeof(v));
		ori.x = p[0]-'a'+1;
		ori.y = p[1]-'0';
		desx = p[3]-'a'+1;
		desy = p[4]-'0';
		ori.g = 0;
		ori.h = mht(ori);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",p[0],p[1],p[3],p[4],astar(ori));
	}

	return 0;
}