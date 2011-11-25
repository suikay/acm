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

using namespace std;
#define N 30
int m[N][N],w,h;
int sx,sy,ex,ey,res;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool thr(int x,int y,int &desx,int &desy,int dir)
{
	desx = x;
	desy = y;
	while(desx >= 0 && desx < h && desy >= 0 && desy < w) {
		if(desx == ex && desy == ey)
			return true;
		if(m[desx+dx[dir]][desy+dy[dir]] == 1) {
			m[desx+dx[dir]][desy+dy[dir]] = 0;
			return true;
		}
		desx += dx[dir];
		desy += dy[dir];
	}
	return false;
}
void pb(int x,int y,int dir)
{
	m[x+dx[dir]][y+dy[dir]] = 1;
}
void dfs(int x,int y,int times)
{
	int tx,ty;
	if(times > 10 || times >= res)
		return ;
	if(x == ex && y == ey && res > times) {
		res = times;
		return;
	}
	for(int i = 0; i < 4; i++) 
		if(thr(x,y,tx,ty,i)) {
			if(tx != x || ty != y)
				dfs(tx,ty,times+1);
			pb(tx,ty,i);
		}
}

int main()
{
	while((cin >> w >> h) && w)
	{
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++) {
				cin >> m[i][j];
				if(m[i][j] == 2) {
					sx = i;
					sy = j;
				}
				if(m[i][j] == 3) {
					ex = i;
					ey = j;
				}
			}
		res = 9999;
		dfs(sx,sy,0);
		if(res != 9999)
			cout << res << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}