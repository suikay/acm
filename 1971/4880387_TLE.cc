#include<memory.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 1000
#define HMAX  0x7FFFFF
struct Point{
	int x;
	int y;
	int count;
	int next;
};
Point p[MAX*MAX];
int head[HMAX];
int x[MAX],y[MAX];
int main()
{
	int t,n;
	int zz,xx,yy,xtmp,ytmp,ptr,res;
	unsigned h;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		ptr = 1;
		res = 0;
		memset(head,0,sizeof(head));
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&xtmp,&ytmp);
			for(int j = 0; j < i; j++)
			{
				flag = true;
				xx = xtmp + x[j];
				yy = ytmp + y[j];
				h = (xx & HMAX + yy & HMAX) & HMAX;
				//h %= HMAX;
				zz = head[h];
				while(zz){
					if(p[zz].x == xx && p[zz].y == yy){
						p[zz].count++;
						res+=p[zz].count;
						flag = false;
						break;
					}
					else
						zz = p[zz].next;
				}
				if(flag)	{
					p[ptr].x = xx;
					p[ptr].y = yy;
					p[ptr].next = head[h];
					head[h] = ptr++;
				}
			}
			x[i] = xtmp;
			y[i] = ytmp;
		}
		printf("%d\n",res);
	}
	return 0;
}