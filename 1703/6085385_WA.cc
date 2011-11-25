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
	static int xx,yy;
	xx = father(x); yy = father(y);
	if(parent[xx] < parent[yy])
		parent[yy] = xx;
	else {
		parent[xx] = yy;
		if(parent[xx] == parent[yy])
			parent[yy]--;
	}
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
			scanf("\n%c%d%d",&ch,&x,&y);
			if(ch == 'A') {
				xx = father(x);	yy = father(y);
				if(xx == yy)
					puts("In the same gang.");
				else if(enermy[xx] == yy)
					puts("In different gangs.");
				else
					puts("Not sure yet.");
			} else {
				xx = father(x); yy = father(y);
				if(enermy[xx] == yy)	break;
				if(enermy[yy]) merge(xx,enermy[yy]);
				if(enermy[xx]) merge(yy,enermy[xx]);
				xx = father(xx); yy = father(yy);
				enermy[xx] = yy; enermy[yy] = xx;
			}
		}
	}

	return 0;
}


/*
2
5 9
D 1 2
D 2 4
D 5 3
A 2 3
A 1 3
D 2 5
A 1 3
A 2 3
A 4 3
5 9
D 1 2
D 2 4
D 5 3
A 2 3
A 1 3
D 2 5
A 1 3
A 2 3
A 4 3
*/


