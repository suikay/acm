#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;
#define NIL 10000001
#define MUL -1
#define M 20000
struct TNode{
	int left,right;
	int no;
};
TNode pst[10*M];
int point[3*M],sz;
int map[M][3];
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
	pst[step].left = s;
	pst[step].right = t;
	pst[step].no = 0;
	if(s == t)
		return;
	int mid = (s + t)>> 1;
	Build(s,mid,step*2);
	Build(mid+1,t,step*2+1);
}

void Insert(int s,int t,int step,int num)
{
	if(pst[step].left == s && pst[step].right == t)	{
		pst[step].no = num;
		return;
	}
	if(pst[step].no != MUL){
		pst[step*2].no = pst[step].no;
		pst[step*2 + 1].no = pst[step].no;
		pst[step].no = MUL;
	}
	int mid = (pst[step].left + pst[step].right) >> 1;
	if(mid >= t){
		Insert(s,t,step*2,num);
		return;
	}
	if(mid < s){
		Insert(s,t,step*2 + 1,num);
		return;
	}
	Insert(s,mid,step*2,num);
	Insert(mid+1,t,step*2+1,num);
	return;
}

bool v[M];
int res;
void Count(int step)
{
	if(pst[step].no == MUL)
	{
		Count(step*2);
		Count(step*2+1);
	}
	else
	{
		if( !v[pst[step].no]){
			res++;
			v[pst[step].no] = true;
		}
	}
	return;
}

int main()
{
	int c,n,tmp,l,r,i;
	scanf("%d",&c);
	while(c--)
	{
		sz = 0;
		res = 0;
		scanf("%d",&n);
		memset(v,false,sizeof(v));
		v[0] = true;
		for(i = 1;i <= n; i++){
			scanf("%d%d",&l,&r);
			point[sz++] = l;
			point[sz++] = r;
			map[i][0] = l;
			map[i][1] = r;
			map[i][2] = i;
		}
		for(i = 0; i < sz; i++)
			for(int j = i + 1; j < sz; j++)
				if(point[i] != point[j])
					break;
				else
					point[j] = NIL;
		sort(point,point+sz);
		while(point[sz-1] == NIL)
			sz--;
		Build(0,sz,1);
		for(i = 1; i <= n; i++)
			Insert(find(map[i][0]),find(map[i][1]),1,map[i][2]);
		Count(1);
		printf("%d\n",res);
	}
	return 0;
}