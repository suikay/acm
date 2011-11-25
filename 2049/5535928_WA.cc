#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 201;
const double ESP = 10e-5;
const int dirx[] = {0,0,-1,1},diry[] = {1,-1,0,0};
int valid[2][N][N],min_door[N][N],desx,desy;
int move(int ax,int ay,int bx,int by)
{
	if(ax == bx)
		return valid[0][ax][max(ay,by)];
	return valid[1][max(ax,bx)][ay];
}

bool input()
{
	float tmpx,tmpy;
	int m,n,x,y,dir,len;
	memset(min_door,0x7f,sizeof(min_door));
	memset(valid,0,sizeof(valid));
	scanf("%d%d",&m,&n);
	if(m == -1)
		return false;
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d%d",&x,&y,&dir,&len);
		if(dir == 0) 
			for(int i = x; i <= x + len; i++)
				valid[0][i][y] = -1;
		else
			for(int i = y; i <= y+len; i++)
				valid[1][x][i] = -1;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d",&x,&y,&dir);
		valid[dir][x][y] = 1;
	}
	scanf("%f%f",&tmpx,&tmpy);
	desx = (int)(tmpx + ESP);
	desy = (int)(tmpy + ESP);
	return true;
}

void dfs(int x,int y)
{
	int xx,yy,type;
	if(xx == desx && yy == desy)
		return;
	for(int i = 0; i < 4; i++) {
		xx = x + dirx[i];
		yy = y + diry[i];
		if(xx < 0 || xx >= 200 || yy < 0 || yy >= 200)
			continue;
		type = move(x,y,xx,yy);
		if(type == -1)
			continue;
		if(min_door[xx][yy] > (min_door[x][y]+type)) {
			min_door[xx][yy] = min_door[x][y]+type;
			dfs(xx,yy);
		}
	}
}

int main()
{
	while(input()) {
		min_door[0][0] = 0;
		if(desx >= 200 || desx < 0 || desy >= 200 || desy < 0)
			printf("0\n");
		else 
		{
			dfs(0,0);
			if(min_door[desx][desy] != 0x7f7f7f7f)
				printf("%d\n",min_door[desx][desy]);
			else
				printf("-1\n");
		}
	}
	return 0;
}