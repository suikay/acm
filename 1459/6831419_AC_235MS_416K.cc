#include <stdio.h>
#include <string.h>
#define N 110
#define INF 0x1fffffff
#define min(x,y) ((x)>(y))?(y):(x)
int f[N][N];
int n,np,nc,rc;
bool input()
{
	int x,y,z;
	memset(f,0,sizeof(f));
	if(scanf("%d%d%d%d",&n,&np,&nc,&rc)!= 4)
		return false;
	for(int i = 0; i < rc; i++) {
		scanf(" (%d,%d)%d",&x,&y,&z);
		if(x == y)
			continue;
		f[x+1][y+1] = z;
	}
	for(int i = 0; i < np;i++) {
		scanf(" (%d)%d",&x,&y);
		f[0][x+1] = y;
	}
	for(int i = 0; i < nc; i++) {
		scanf(" (%d)%d",&x,&y);
		f[x+1][n+1] = y;
	}

	return true;
}

int queue[N],top,path[N],con[N];
int bfs()
{
	int u;
	top = 0;
	queue[top++] = 0;
	memset(path,-1,sizeof(path));
	memset(con,0,sizeof(con));
	con[0] = INF;
	while(top--)
	{
		u = queue[top];
		for(int i = 1; i <= n+1; i++)
			if(f[u][i] && !con[i]) {
				con[i] = min(f[u][i],con[u]);
				path[i] = u;
				if(i == n+1)
					return con[i];
				queue[top++] = i;
		}
	}

	return -1;
}

int ff()
{
	int u,tmp,res = 0;
	while((tmp = bfs()) != -1)
	{
		//printf("HERE %d\n",tmp);
		res += tmp;
		u = n+1;
		while(u) {
			f[path[u]][u] -= tmp;
			f[u][path[u]] += tmp;
			u = path[u];
		}
	}
	return res;
}

int main(int argc, char *argv[])
{

	while(input())
		printf("%d\n",ff());
	
	return 0;
}
