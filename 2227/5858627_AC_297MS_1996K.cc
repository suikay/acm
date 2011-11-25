#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
struct Node
{
	int h,x,y;
	inline bool operator<(const Node &x) const {
		return h > x.h;
	}
};
const int N = 310;
int ori[N][N],mh[N][N],H,W;
bool ch[N][N];
int dirx[] = {0,1,0,-1},diry[] = {1,0,-1,0};
long long bfs()
{
	priority_queue<Node> pq;
	Node tmp,tmp2;
	int xx,yy;
	for(int i = 1; i <= H; i++) {
		tmp.x = i; tmp.y = 1; tmp.h = ori[i][1]; pq.push(tmp); mh[i][1] = ori[i][1];
		tmp.x = i; tmp.y = W; tmp.h = ori[i][W]; pq.push(tmp); mh[i][W] = ori[i][W];
	}
	for(int i = 2; i < W; i++) {
		tmp.x = 1; tmp.y = i; tmp.h = ori[1][i]; pq.push(tmp); mh[1][i] = ori[1][i];
		tmp.x = H; tmp.y = i;tmp.h = ori[H][i]; pq.push(tmp); mh[H][i] = ori[H][i];
	}
	while(!pq.empty())
	{
		tmp = pq.top(); pq.pop();
		if(ch[tmp.x][tmp.y] && tmp.h >= mh[tmp.x][tmp.y])
			continue;
		ch[tmp.x][tmp.y] = true;
		for(int i = 0; i < 4; i++) {
			xx = tmp.x + dirx[i]; yy = tmp.y + diry[i];
			if(xx > 0 && xx <= H && yy > 0 && yy <= W &&
				((tmp.h < mh[xx][yy] && mh[xx][yy] > ori[xx][yy]))) {
					tmp2.x = xx; tmp2.y = yy; mh[xx][yy] = tmp2.h = max(ori[xx][yy],tmp.h);
					pq.push(tmp2);
			}
		}
	}
	long long res(0);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			res += mh[i][j]-ori[i][j];
	return res;
}
void input()
{
	scanf("%d%d",&W,&H);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			scanf("%d",&ori[i][j]);
	memset(mh,0x7f,sizeof(mh));
	memset(ch,false,sizeof(ch));
}
int main()
{
	input();
	printf("%I64d\n",bfs());
	return 0;
}
/*
3 3 
2 2 2
2 1 2
2 2 2
4 4
2 2 2 2
2 1 1 2
2 1 1 2
2 2 2 2
5 5
3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3
4 5
5 8 7 7
5 2 1 5
7 1 7 1
8 9 6 9
9 8 9 9
*/