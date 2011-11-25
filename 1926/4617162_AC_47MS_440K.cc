#include<memory.h>
#include<stdio.h>
#include<iostream>
bool adj[110][110],v[110];
int degree[110],n,m;
double con[110],sum[110];
void input()
{
	int x,y;
	memset(adj,false,sizeof(adj));
	memset(degree,0,sizeof(degree));
	memset(v,false,sizeof(v));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		std::cin >> con[i];
		adj[i][i]=true;
	}
	for(int i=1; i<=m; i++)	{
		scanf("%d%d",&x,&y);
		adj[x][y]=adj[y][x]=true;
		degree[x]++;
		degree[y]++;
	}
}
void dfs()
{
	bool flag=false;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				adj[j][k] |= (adj[j][i]&&adj[i][k]);
	double tmp,dtmp;
	for(int i=1; i<=n; i++)
		if(!v[i]){
			tmp=0.0;
			dtmp=0.0;
			for(int j=1; j<=n; j++)
				if(adj[i][j])	{
					tmp+=con[j];
					dtmp+=degree[j];
					v[j] = true;
				}
			if(dtmp-0>10e-6){
				tmp/=dtmp;
				for(int j=1; j<=n; j++)
					if(adj[i][j])
						sum[j]=tmp*degree[j];
			}
			else
				sum[i]=tmp;					
		}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		input();
		dfs();
		for(int i=1; i<=n; i++)
			printf("%.3f\n",sum[i]);
		printf("\n");
	}
	return 0;
}
