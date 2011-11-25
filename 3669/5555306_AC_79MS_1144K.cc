#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 310;
const int INF = 0x7f7f7f7f;
int hit[N][N],res;
int stx[N*N],sty[N*N],stt[N*N];
bool v[N][N];
int dirx[]={0,0,-1,1};
int diry[]={1,-1,0,0};
int bfs()
{
	int top,end,now;
	int tx,ty,tt,t,x,y;
	if(hit[0][0] == INF)
		return 0;
	top = end = 0;
	stx[end] = 0;
	sty[end] = 0;
	stt[end++] = 0;
	while(top < end) {
		tx = stx[top];
		ty = sty[top];
		tt = stt[top++];
		t = tt+1;
		for(int i = 0; i < 4; i++) {
			x = tx+dirx[i];
			y = ty+diry[i];
			if(x >= 0 && y >= 0 && !v[x][y] && hit[x][y] > t) {
				if(hit[x][y] == INF)
					return t;
				stx[end] = x;
				sty[end] = y;
				stt[end++] = t;
				v[x][y] = true;
			}
		}
	}
	return -1;
}


int main()
{
	int m,x,y,t;
	scanf("%d",&m);
	memset(hit,0x7f,sizeof(hit));
	res = INF;
	for(int i = 0; i < m; i++) 
	{
		scanf("%d%d%d",&x,&y,&t);
		if(hit[x][y] > t)
			hit[x][y] = t;
		if(x > 0 && hit[x-1][y] > t)
			hit[x-1][y] = t;
		if(y > 0 && hit[x][y-1] > t)
			hit[x][y-1] = t;
		if(hit[x+1][y] > t)
			hit[x+1][y] = t;
		if(hit[x][y+1] > t)
			hit[x][y+1] = t;
	}
	cout << bfs() << endl;

	return 0;
}