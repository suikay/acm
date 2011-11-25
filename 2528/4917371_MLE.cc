#include<stdio.h>
#include<memory.h>
#define M 11000000
#define N 11000
#define NO 0
#define MUL -1
struct TNode{
	int left,right;
	int what;
};
TNode poster[3*M];
int res;
bool v[N];
void Build(int s,int t,int step)
{
	int mid;
	poster[step].left = s;
	poster[step].right = t;
	poster[step].what = NO;
	if(s == t)
		return;
	mid = (s + t) >> 1;
	Build(s,mid,step*2);
	Build(mid+1,t,step*2+1);
	return;
}

void insert(int s,int t,int step,int which)
{
	if(s == poster[step].left && t == poster[step].right){
		poster[step].what = which;
		return;
	}
	if(poster[step].what != MUL) {
		poster[step*2].what = poster[step].what;
		poster[step*2+1].what = poster[step].what;
		poster[step].what = MUL;
	}
	int mid = (poster[step].left + poster[step].right) >> 1;
	if(s > mid){
		insert(s,t,step*2+1,which);
		return;
	}
	if(t <= mid){
		insert(s,t,step*2,which);
		return;
	}
	insert(s,mid,step*2,which);
	insert(mid+1,t,step*2+1,which);
}

void cal(int step)
{
	if(poster[step].what != MUL){
		if(v[poster[step].what] == false){
			res++;
			v[poster[step].what] = true;
		}
	}
	else
	{
		cal(step*2);
		cal(step*2+1);
	}
}

int main()
{
	int n,l,r,k;
	scanf("%d",&n);
	while(n--)
	{
		memset(v,false,sizeof(v));
		v[NO] = true;
		res = 0;
		scanf("%d",&k);
		Build(1,M,1);
		for(int i = 1; i <= k; i++)
		{
			scanf("%d%d",&l,&r);
			insert(l,r,1,i);
		}
		cal(1);
		printf("%d\n",res);
	}
	return 0;
}