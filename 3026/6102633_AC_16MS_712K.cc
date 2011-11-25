#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
const int N = 52;
short type[N][N];
struct Point
{
	int x,y,dis;
	bool operator<(const Point &p) const{
		return dis > p.dis;
	}
	Point(int xx,int yy,int dd):x(xx),y(yy),dis(dd) {}
	Point() {}
};
int dis[N][N];
int dirx[] = {0,0,-1,1},diry[] = {-1,1,0,0};
int m,n,acnt,orix,oriy;
bool valid(int x,int y) {
	return x >= 0 && x < n && y >= 0 && y < m && type[x][y] != 1;
}
char tmp[N];
void input()
{
	char ch;
	scanf("%d%d",&m,&n);
	gets(tmp);
	memset(type,0,sizeof(type));
	for(int i = 0; i < n; i++) {
		gets(tmp);
		for(int j = 0 ;j < m; j++) {
			ch = tmp[j];
			if(ch == '#')
				type[i][j] = 1;
			else if(ch == 'A') {
				type[i][j] = -1;
				acnt++;
			} else if(ch == 'S') {
				orix = i; oriy = j;
			}
		}
	}
}
priority_queue<Point> pq;
int bfs()
{
	int xx,yy,res;
	Point p;
	while(!pq.empty())
		pq.pop();
	memset(dis,0x3f,sizeof(dis));
	dis[orix][oriy] = 0;
	res = 0;
	pq.push(Point(orix,oriy,0));
	while(acnt) {
		p = pq.top(); pq.pop();
		//cout << " T " << p.x << " " << p.y << " " << p.dis << " " << pq.size() <<endl;
		if(type[p.x][p.y] == -1) {
			acnt--;
			res += p.dis;
			//cout << p.x << " "<< p.y << " " << p.dis << " " << res << endl;
			dis[p.x][p.y] = 0;
			type[p.x][p.y] = 0;
			pq.push(Point(p.x,p.y,0));
			continue;
		}
		for(int i = 0; i < 4; i++) {
			xx = p.x + dirx[i];
			yy = p.y + diry[i];
			if(valid(xx,yy) && dis[xx][yy] > p.dis+1) {
				dis[xx][yy] = p.dis+1;
				pq.push(Point(xx,yy,p.dis+1));
			}
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		printf("%d\n",bfs());
	}

	return 0;
}
/*
2
6 5
##### 
#A#A##
# # A#
#S  ##
##### 
7 7
#####  
#AAA###
#    A#
# S ###
#     #
#AAA###
#####  
*/
