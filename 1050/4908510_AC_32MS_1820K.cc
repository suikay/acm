#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
#define N 525
#define NNIL -9999999
int n,d[N][N];
int t[N][N],max[N][N];
void input()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d",&d[i][j]);
}
int dp()
{
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			max[i][j] = NNIL;
	int record(NNIL);
	for(int i = 1; i <= n; i++)	{
		memset(t,0,sizeof(t));
		for(int j = 1; j <= n; j++)
			for(int k = j; k <= n; k++)	{
				t[j][k]=t[j][k-1]+d[i][k];
				if(max[j][k]>0)
					max[j][k]+=t[j][k];
				else
					max[j][k]=t[j][k];
				if(max[j][k]>record)
					record=max[j][k];
			}
	}
	return record;
}
int main()
{
	input();
	printf("%d\n",dp());
	return 0;
}
