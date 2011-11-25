#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define NIL 1111111111
#define M 41000
#define MUL -1
struct TNode{
	int left,right;
	int h;
};
TNode b[10*M];
int point[3*M],sz;

int find(int x)
{
	int left(0),right(sz);
	int mid = (left + right) >> 1;
	while(x != point[mid]){
		if(point[mid] > x)
			right = mid;
		else
			left = mid;
		mid = (left + right) >> 1;
	}
	return mid;
}

void Build(int s,int t,int step)
{
	b[step].left = s;
	b[step].right = t;
	b[step].h = 0;
	if((s+1) == t)
		return;
	int mid = (s + t) >> 1;
	Build(s,mid,step*2);
	Build(mid,t,step*2+1);
	return;
}

void Insert(int s,int t,int step,int height)
{
	if(b[step].left == s && b[step].right == t && b[step].h != MUL){
		b[step].h = (b[step].h>height)?b[step].h:height;
		return;
	}
	if(b[step].h != MUL){
		b[step*2].h = b[step].h;
		b[step*2+1].h = b[step].h;
		b[step].h = MUL;
	}
	int mid = (b[step].left + b[step].right) >> 1;
	if(mid >= t)
	{
		Insert(s,t,step*2,height);
		return;
	}
	if(mid <= s)
	{
		Insert(s,t,step*2+1,height);
		return;
	}
	Insert(s,mid,step*2,height);
	Insert(mid,t,step*2+1,height);
}

long long res(0);
void Count(int step)
{
	if(b[step].h != MUL)
		res += ((long long)b[step].h) * ((long long)point[b[step].right] - (long long)point[b[step].left]);
	else
	{
		Count(step*2);
		Count(step*2+1);
	}
	return;
}

int main()
{
	int map[M][3];
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)	{
		scanf("%d%d%d",&map[i][0],&map[i][1],&map[i][2]);
		point[sz++] = map[i][0];
		point[sz++] = map[i][1];
	}
	sort(point,point+sz);
	for(int i = 0; i < sz; i++)
		for(int j = i + 1; j < sz; j++)
			if(point[i] != point[j])
				break;
			else
				point[j] = NIL;
	sort(point,point+sz);
	while(point[sz-1] == NIL)
		sz--;
	Build(0,sz-1,1);
	for(int i = 1; i <= n; i++)
		Insert(find(map[i][0]),find(map[i][1]),1,map[i][2]);
	Count(1);
	cout << res << endl;
	return 0;
}