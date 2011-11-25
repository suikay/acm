//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//int step[102][102], height[102][102];
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int r, c;
//bool go()
//{
//	bool ok = false;
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//			for (int k = 0; k < 4; k++)
//				if (height[i][j] > height[dx[k]+i][dy[k]+j]
//					&& step[i][j] <= step[dx[k]+i][dy[k]+j])
//				{
//					ok = true;
//					step[i][j] = step[dx[k]+i][dy[k]+j] + 1;
//				}
//	return ok;
//}
//
//int max()
//{
//	int res = 0;
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//			res = (res < step[i][j])?step[i][j]:res;
//
//	return res;
//}
//
//int main(int argc, char *argv[])
//{
//	scanf("%d%d", &r, &c);
//	memset(height, -1, sizeof(height));
//
//	//cout << step[0][0] << endl;
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//		{
//			step[i][j] = -99999;
//			scanf("%d", &height[i][j]);
//		}
//
//	while (go());
//	printf("%d\n", max());
//
//	return 0;
//}

/*
3 3
1 2 3
6 5 4
7 9 9
4 4
9 9 9 9
9 1 2 9
9 4 3 9
9 9 9 9
3 3
0 0 0
0 1 0
0 0 0
*/
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
class Point {
public:
	int x, y, h;
	bool operator<(const Point &p) const{
		return h < p.h;
	}
} ;
int main()
{
	priority_queue<Point> pq;
	int r, c, step[102][102], height[102][102];
	Point p;
	while (scanf("%d%d", &r, &c) == 2)
	{
		memset(height, -1, sizeof(height));
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				scanf("%d", &p.h);
				p.x = i; p.y = j;
				height[i][j] = p.h;
				pq.push(p);
			}
		memset(step, 0, sizeof(step));
		while (!pq.empty())
		{
			p = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++)
				if (height[p.x+dx[i]][p.y+dy[i]] < height[p.x][p.y]
					&& step[p.x+dx[i]][p.y+dy[i]] <= step[p.x][p.y])
					step[p.x+dx[i]][p.y+dy[i]] = step[p.x][p.y] + 1;
		}
		int res = 1;
		for (int i = 0; i <= r+1; i++)
			for (int j = 0; j <= c+1; j++)
				if (res < step[i][j])
					res = step[i][j];
		printf("%d\n", res);
	}
		

	return 0;
}
