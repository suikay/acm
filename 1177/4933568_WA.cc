#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define M 5000
#define lb -10000
#define MUL -99999
struct TNode{
	int left,right;
	int up,down;
	int area;
};
TNode sq[3*M];

int x[2*M],xsz;
int find(int want)
{
	int left(0),right(xsz);
	int mid = (left + right) >> 1;
	while(x[mid] != want)	{
		if(x[mid] > want)
			right = mid;
		else
			left = mid;
		mid = (left + right )>> 1;
	}
	return mid;
}

void Build(int s,int t,int step)
{
	sq[step].left = s;
	sq[step].right = t;
	sq[step].up = lb;
	sq[step].down = lb;
	sq[step].area = 0;
	if((s+1) == t)
		return;
	int mid = (s + t) >> 1;
	Build(s,mid,step*2);
	Build(mid,t,step*2+1);
}

void Insert(int s,int t,int step,int u,int d)
{
	if(sq[step].left == s && sq[step].right == t && sq[step].up != MUL)
	{
		if(sq[step].down < u)
			sq[step].area += (x[sq[step].right] - x[sq[step].left]) * (sq[step].down - sq[step].up);
		sq[step].up = u;
		sq[step].down = d;
		return;
	}
	if(sq[step].up != MUL){
		sq[step*2].up = sq[step].up;
		sq[step*2].down = sq[step].down;
		sq[step*2+1].up = sq[step].up;
		sq[step*2+1].down = sq[step].down;
		sq[step].up = MUL;
	}
	int mid = (sq[step].left + sq[step].right) >> 1;
	if(mid >= t)
		Insert(s,t,step*2,u,d);
	else
		if(mid <= s)
			Insert(s,t,step*2+1,u,d);
		else	{
			Insert(s,mid,step*2,u,d);
			Insert(mid,t,step*2+1,u,d);
		}
}

int res;
void Count(int step)
{
	res += sq[step].area;
	if(sq[step].up != MUL)
		res += (x[sq[step].right] - x[sq[step].left]) * (sq[step].down - sq[step].up);
	else	{
		Count(step*2);
		Count(step*2+1);
	}
}

struct Map{
	int x1,y1,x2,y2;
	bool operator()(Map a,Map b)	{
		if(a.y1 == b.y1)
			return a.y2 < b.y2;
		else
			return a.y1 < b.y1;
	}
};

int main()
{
	int n;
	Map map[M];
	cin >> n;
	for(int i = 0; i < n; i++)	{
		cin >> map[i].x1 >> map[i].y1 >> map[i].x2 >> map[i].y2;
		x[i] = map[i].x1;
		x[i+n] = map[i].x2;
	}
	sort(map,map+n,Map());

	sort(x,x+2*n);
	xsz = 1;
	for(int i = 1; i < 2*n; i++)
		if(x[i] != x[i-1])
			x[xsz++] = x[i];

	Build(0,xsz-1,1);
	for(int i = 0; i < n; i++)
		Insert(find(map[i].x1),find(map[i].x2),1,map[i].y1,map[i].y2);
	Count(1);
	cout << res << endl;
	return 0;
}
	