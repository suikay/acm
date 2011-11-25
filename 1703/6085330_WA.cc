#include <string.h>
#include <stdio.h>
#define N 110000
int enermy[N],parent[N],q[N];
int father(int x)
{
	static int now;
	now = 0;
	while(parent[x] >= 0)
	{
		q[now++] = x;
		x = parent[x];
	}
	for(int i = 0; i < now; i++)
		parent[q[i]] = x;
	return x;
}
void merge(int x,int y)
{
	//printf("M %d %d\n",x,y);
	static int xx,yy;
	xx = father(x); yy = father(y);
	if(parent[xx] < parent[yy])
		parent[yy] = xx;
	else {
		parent[xx] = yy;
		if(parent[xx] == parent[yy])
			parent[yy]--;
	}
	//printf("MM %d %d\n",xx,yy);
}
char query[100];
int main()
{
	int t,x,xx,y,yy,m,n;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(enermy,0,sizeof(enermy));
		memset(parent,-1,sizeof(parent));
		while(m--)
		{
			scanf("%s",query);
			sscanf(query,"%c",&ch);
			scanf("%d%d",&x,&y);
			if(ch == 'A') {
				xx = father(x);	yy = father(y);
				//printf("%d %d\n",xx,yy);
				if(xx == yy)
					puts("In the same gang.");
				else if(enermy[xx] == yy)
					puts("In different gangs.");
				else
					puts("Not sure yet.");
			} else {
				xx = father(x); yy = father(y);
				if(enermy[xx] == yy)	break;
				//printf("EN %d %d | %d %d\n",xx,enermy[xx],yy,enermy[yy]);
				if(enermy[yy]) merge(xx,enermy[yy]);
				if(enermy[xx]) merge(yy,enermy[xx]);
				xx = father(xx); yy = father(yy);
				enermy[xx] = yy; enermy[yy] = xx;
				//printf("EN %d %d | %d %d\n",xx,enermy[xx],yy,enermy[yy]);
				//printf("EE %d\n",parent[4]);
			}
		}
	}

/*
1
5 9
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
D 4 5
D 4 3
A 1 3
A 3 5
*/







	return 0;
}
