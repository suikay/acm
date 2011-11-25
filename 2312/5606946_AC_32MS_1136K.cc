//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>
//#include <queue>
//using namespace std;
//struct Tank
//{
	//int h,g,x,y;
	//Tank(){}
	//Tank(int xx,int yy,int hh,int gg) {
		//x = xx; y = yy; h = hh; g = gg;
	//}
	//bool operator<(const Tank &t) const{
		//return (this->h+this->g)>(t.h+t.g);
	//}
//};
//int dirx[]={0,0,1,-1},diry[]={1,-1,0,0};
//int m,n,ox,oy,dx,dy;
//const int N = 310;
//Tank t[N][N];
//char b[N][N];
//bool v[N][N],push[N][N];
//priority_queue<Tank> pt;

//int mht(int x,int y)
//{
	//return abs(x-dx)+abs(y-dy);
//}
//void change(Tank &tmp,int x,int y,int h,int g) {
	//tmp.x = x;
	//tmp.y = y;
	//tmp.g = g;
	//tmp.h = h;
//}

//int astar()
//{
	//Tank now,tmp;
	//int xx,yy,gg,x,y,h,g;
	//change(t[ox][oy],ox,oy,0,0);
	//pt.push(t[ox][oy]);
	//push[ox][oy] = true;
	//while(!pt.empty())
	//{
		//now = pt.top();
		//pt.pop();
		//xx = now.x;
		//yy = now.y;
		//gg = now.g;
		//v[xx][yy] = true;
		//for(int i = 0; i < 4; i++) {
			//x = xx+dirx[i];
			//y = yy+diry[i];
			//if(x == dx && y == dy) 
				//return gg+1;
			//if(x < 0 || y < 0 || x >= m || y >= n || v[x][y] ||
				//b[x][y] == 'S' || b[x][y] == 'R')
				//continue;
			//h = mht(x,y);
			//g = (b[x][y]=='B')?(gg+2):(gg+1);
			//if((h+g) >= (t[x][y].h+t[x][y].g))
				//continue;
			//change(t[x][y],x,y,h,g);
			//if(!push[x][y]) {
				//pt.push(t[x][y]);
				//push[x][y] =  true;
			//}
		//}
	//}
	//return -1;
//}
	
//int main()
//{
	//while(true)
	//{
		//while(!pt.empty())
			//pt.pop();
		//memset(v,false,sizeof(v));
		//memset(push,false,sizeof(push));
		//scanf("%d%d",&m,&n);
		//if(!m && !n)
			//return 0;
		//for(int i = 0; i < m; i++) {
			//cin >> b[i];
			//for(int j = 0; j < n ;j++) {
				//change(t[i][j],i,j,0x0fffffff,0x0fffffff);
				//if(b[i][j] == 'Y') {
					//ox = i;
					//oy = j;
				//} else if(b[i][j] == 'T') {
					//dx = i;
					//dy = j;
				//}
			//}
		//}
		//printf("%d\n",astar());
	//}

	//return 0;
//}
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
	int h,g,x,y;
	Tank(){}
	Tank(int xx,int yy,int hh,int gg) {
		x = xx; y = yy; h = hh; g = gg;
	}
	bool operator<(const Tank &t) const{
		return (this->h+this->g)>(t.h+t.g);
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
Tank tank(int x,int y,int g,int h) {
	static Tank tmp;
	v[x][y] == true;
	tmp.x = x;
	tmp.y = y;
	tmp.g = g;
	tmp.h = h;
	return tmp;
}

int astar()
{
	Tank now;
	int xx,yy,gg,x,y,h,g;
	pt.push(Tank(ox,oy,0,0));
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
			h = mht(x,y);
			g = (b[x][y]=='B')?(gg+2):(gg+1);
			if((h+g) >= v[x][y])
				continue;
			v[x][y] = h+g;
			pt.push(Tank(x,y,h,g));
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
		if(!m && !n)
			return 0;
		for(int i = 0; i < m; i++) {
			cin >> b[i];
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