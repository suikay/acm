#include<memory.h>
#include<stdio.h>
#define N 102
int lm[N][N];
bool input()
{
	int n,l,m;
	memset(lm,0,sizeof(lm));
	scanf("%d",&n);
	if(!n)
		return false;
	for(int i=0; i<n; i++)	{
		scanf("%d%d",&l,&m);
		lm[l][m]++;
	}
	return true;
}
int dp()
{
	int max;
	for(int i = 1; i < 101; i++)	{
		max=lm[i][1];
		lm[i+1][1]+=max;
		for(int j = 2; j < 101; j++)	{
			if(lm[i][j]>max)
				max = lm[i][j];
			lm[i+1][j]+=max;
		}
	}
	return max;
}
int main()
{
	while(input())
		printf("%d\n",dp());
	printf("*\n");
	return 0;
}
