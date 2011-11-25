#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char ma[11][11];
int v[11][11];
int m,n,ori;

bool valid(int x, int y) {
	return (x >= 0 && x < m && y >= 0 && y < n);
}

bool input()
{
	scanf("%d%d%d",&m,&n,&ori);
	if(!m)
		return false;
	for(int i = 0; i < m; i++)
		scanf("%s",ma[i]);
	return true;
}

void mov(int &x,int &y,char dir)
{
	switch(dir) {
		case 'N':	--x; break;
		case 'S':	++x; break;
		case 'E':	++y; break;
		case 'W':	--y; break;
	}
	return;
}

int main()
{
	int nx,ny,tx,ty,step;
	while(input())
	{
		nx = 0; ny = ori-1;
		memset(v,0,sizeof(v));
		step = 0;
		while(!v[nx][ny]) 
		{
			v[nx][ny] = ++step;
			tx = nx; ty = ny;
			mov(nx,ny,ma[nx][ny]);
			if(!valid(nx,ny))
				break;
		}
		if(!valid(nx,ny))
			printf("%d step(s) to exit\n",v[tx][ty]);
		else
			printf("%d step(s) before a loop of %d step(s)\n",v[nx][ny]-1,step-v[nx][ny]+1);
	}

	return 0;
}
