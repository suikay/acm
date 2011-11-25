#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 110;
int block[N][N];
int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};
int A,B,M,n;
struct Robot
{
	int x,y,dir;
};
Robot r[N];
int move(int which,char type)
{
	static int xx,yy;
	if(type == 'F') {
		xx = r[which].x + dirx[r[which].dir];
		yy = r[which].y + diry[r[which].dir];
		if(xx < 0 || xx > A || yy < 0 || yy > B)
			return -1;
		if(block[xx][yy])
			return block[xx][yy];
		block[r[which].x][r[which].y] = 0;
		r[which].x = xx;
		r[which].y = yy;
		block[xx][yy] = which;
		return 0;
	}
	if(type == 'L') 
		r[which].dir = (r[which].dir + 1) % 4;
	if(type == 'R')
		r[which].dir = (r[which].dir + 3) % 4;
	return 0;
}
void input()
{
	char d;
	memset(block,0,sizeof(block));
	cin >> A >> B;
	cin >> n >> M;
	for(int i = 1; i <= n; i++) {
		cin >> r[i].x >> r[i].y;
		block[r[i].x][r[i].y] = i;
		cin >> d;
		switch(d) {
			case 'E':	r[i].dir = 0;break;
			case 'N':	r[i].dir = 1;break;
			case 'W':	r[i].dir = 2;break;
			case 'S':	r[i].dir = 3;break;
		}
	}
}

int main()
{
	int k,which,r,cr;
	char d;
	int res;
	cin >> k;
	while(k--)
	{
		res = 0;
		input();
		for(int i = 0; i < M; i++) {
			cin >> which >> d >> r;
			if(res)
				continue;
			if(d != 'F')
				r %= 4;
			for(int j = 0; j < r; j++) {
				res = move(which,d);
				if(res){
					cr = which;
					break;
				}
			}
		}
		if(res == 0) 
			cout << "OK" << endl;
		else 
			if(res < 0)
				cout << "Robot " << cr << " crashes into the wall" << endl;
			else
				cout << "Robot " << cr << " crashes into robot " << res << endl;
	}

	return 0;
}