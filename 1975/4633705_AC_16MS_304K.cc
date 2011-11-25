#include<memory.h>
#include<stdio.h>
#define N 100
#define MS(_array,_val) memset(_array,_val,sizeof(_array))
bool d1[N][N],d2[N][N];
int c1[N],c2[N];
int n,m;
void bf(bool d[N][N],int c[N])
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				d[j][k]|=(d[j][i]&&d[i][k]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(d[i][j])
				c[i]++;
}
int main()
{
	int tc,res,a,b;
	scanf("%d",&tc);
	while(tc--)	{
		res=0;
		MS(d1,false);
		MS(d2,false);
		MS(c1,0);
		MS(c2,0);
		scanf("%d%d",&n,&m);
		for(int i=0; i<m; i++){
			scanf("%d%d",&a,&b);
			d1[a][b]=true;
			d2[b][a]=true;
		}
		bf(d1,c1);
		bf(d2,c2);
		for(int i=1; i<=n; i++)
			if(c1[i]>n/2||c2[i]>n/2)
				res++;
		printf("%d\n",res);
	}
	return 0;
}