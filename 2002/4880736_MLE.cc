#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define MAX 1000
#define P 70000000
#define clean(x) memset((x),0,sizeof(x))
int dx[MAX*MAX],dy[MAX*MAX],len[MAX*MAX];
int next[MAX*MAX];
int head[P];
int x[MAX],y[MAX];
int main()
{
	int n,xx,yy,ddx,ddy,zz,res,ptr,llen;
	bool flag;
	while(scanf("%d",&n) && n)
	{
		clean(head);
		res = 0;
		ptr = 1;
		for(int i = 0; i < n; i++)
			scanf("%d%d",&x[i],&y[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
			{
				flag = true;
				xx = x[i] + x[j] + 4000;
				yy = y[i] + y[j] + 4000;
				zz = head[xx*4001 + yy];
				ddx = x[i] - x[j];
				ddy = y[i] - y[j];
				llen = ddx*ddx + ddy*ddy;
				while(zz && flag)
					if(len[zz] == llen && (dx[zz]*ddx+dy[zz]*ddy)==0){
						res++;
						flag = false;
					}
					else
						zz = next[zz];
				if(flag){
					dx[ptr] = ddx;
					dy[ptr] = ddy;
					len[ptr] = llen;
					next[ptr] = head[xx*4001 + yy];
					head[xx*4001+yy] = ptr++;
				}
			}
			printf("%d\n",res);
	}
	return 0;
}
