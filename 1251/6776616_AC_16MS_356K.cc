#include <stdio.h>
#include <string.h>
#define N 30
#define INF 0x7f7f7f7f
int dis[N][N];
int edge[N];
int main(int argc, char *argv[])
{
	int n,tmp,cnt,res,v,min;
	char ori,dst;
	while(scanf("%d",&n) && n)
	{
		res = 0;
		memset(dis,0x7f,sizeof(dis));
		for(int j = 1; j < n; j++)
			{
				do {
					ori = getchar();
				} while(!(ori >= 'A' && ori <= 'Z'));
				scanf("%d",&cnt);
				ori -= 'A';
				for(int i = 0; i < cnt; i++) 
				{
					do {
						dst = getchar();
					} while(!(dst >= 'A' && dst <= 'Z'));
					scanf("%d",&tmp);
					dst -= 'A';
					dis[ori][dst] = dis[dst][ori] = tmp;
				}
			}
		memcpy(edge,dis,sizeof(edge));
		edge[0] = -1;
		for(int i = 1; i < n; i++)
		{
			v = -1;
			min = INF;
			for(int j = 0; j < n; j++)
				if(edge[j] >= 0 && edge[j] < min) {
					min = edge[j];
					v = j;
				}
			res += min;
			edge[v] = -1;
			for(int j = 0; j < n; j++)
				if(dis[v][j] < edge[j])
					edge[j] = dis[v][j];
		}
		printf("%d\n",res);
	}
	return 0;
}
