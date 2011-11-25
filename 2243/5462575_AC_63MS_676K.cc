#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct Point {
	int x,y,num;
};
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {1,-1,2,-2,-2,2,1,-1};
Point st[1000];
bool v[100][100];
int bfs(int x1,int y1,int x2,int y2)
{
	memset(v,false,sizeof(v));
	int top,end;
	int tx,ty;
	top = end = 0;
	v[x1][y1] = true;
	st[end].x = x1;
	st[end].y = y1;
	st[end++].num = 0;
	while(top < end) 
	{
		if(st[top].x == x2 && st[top].y == y2)
			return st[top].num;
		for(int i = 0; i < 8; i++) {
			tx = st[top].x + dx[i];
			ty = st[top].y + dy[i];
			if(tx > 0 && tx < 9 && ty > 0 && ty < 9
				&& !v[tx][ty]) {
					st[end].x = tx;
					st[end].y = ty;
					st[end++].num = st[top].num + 1;
					v[tx][ty] = true;
				}
		}
		top++;
	}
	return 0;
}
int main()
{
	char x1,x2;
	int y1,y2;
	while(cin >> x1 >> y1 >> x2 >> y2)
		printf("To get from %c%d to %c%d takes %d knight moves.\n",\
			x1,y1,x2,y2,bfs(x1-'a'+1,y1,x2-'a'+1,y2));
	return 0;
}
