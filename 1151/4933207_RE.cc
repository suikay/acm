#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
#define M 110
#define MUL -1
struct TNode{
	int left,right;
	double up,down;
	double area;
};
TNode sq[4*M];
float x[2*M];
int xsz;
int findx(double want)
{
	int left(0),right(xsz);
	int mid = (left + right) >> 1;
	while(fabs(x[mid] - want) > 10e-4)	{
		if(x[mid] > want)
			right = mid;
		else
			left = mid;
		mid = (left + right) >> 1;
	}
	return mid;
}

void Build(int s,int t,int step)
{
	sq[step].left = s;
	sq[step].right = t;
	sq[step].up = 0.0;
	sq[step].down = 0.0;
	sq[step].area = 0.0;
	if((s + 1) == t)
		return;
	int mid = (s + t) >> 1;
	Build(s,mid,step*2);
	Build(mid,t,step*2+1);
}

void Insert(int s, int t,int step,double u,double d)
{
	if(sq[step].left == s && sq[step].right == t && sq[step].up > -0.5)
	{
		if(u >= sq[step].down)	{
			//如果这个位置 之前的square与现在插入的square不相交则将面积记录下来,更新up和down
			sq[step].area += ( x[sq[step].right] - x[sq[step].left]) * (sq[step].down - sq[step].up);
			sq[step].up = u;
			sq[step].down = d;
		}
		else
			sq[step].down = d;
		return;
	}
	if(sq[step].up > -0.5)	{
		sq[step*2].up = sq[step].up;
		sq[step*2+1].up = sq[step].up;
		sq[step*2].down = sq[step].down;
		sq[step*2+1].down = sq[step].down;
		sq[step].up = MUL;
	}
	int mid = (sq[step].left + sq[step].right ) >> 1;
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

double res(0.0);
void Count(int step)
{
	if(sq[step].up > -0.5)	{
		res += (x[sq[step].right] - x[sq[step].left]) * (sq[step].down - sq[step].up);
		res += sq[step].area;
	}
	else	{
		res += sq[step].area;
		Count(step*2);
		Count(step*2+1);
	}
}

struct Map{
	float x1,y1,x2,y2;
	bool operator()(Map a,Map b)	{
		if(a.y1 == b.y1)
			return a.y2 < b.y2;
		else
			return a.y1 < b.y1;
	}
};

int main()
{
	int n,time(1);
	Map map[M];
	while(scanf("%d",&n) && n)
	{
		res = 0.0;
		for(int i = 0; i < n; i++)	{
			scanf("%f%f%f%f",&(x[i]),&(map[i].y1),&(x[i+n]),&(map[i].y2));
			map[i].x1 = x[i];
			map[i].x2 = x[i+n];
		}
		//先对map进行排序
		sort(map,map+n,Map());

		//将x和y里面的重复的值去掉
		sort(x,x+2*n);
		int index = 1;
		for(int i = 1; i < 2*n ; i++)
			if(x[i] != x[i-1])
				x[index++] = x[i];
		xsz = index;

		//建树
		Build(0,xsz-1,1);
		for(int i = 0; i < n; i++)
			//按下标插入
			Insert(findx(map[i].x1),findx(map[i].x2),1,map[i].y1,map[i].y2);
		Count(1);
		printf("Test case #%d\n",time++);
		printf("Total explored area: %.2f\n\n",res);
	}
	return 0;
}
// suikay 348K 0MS G++ 