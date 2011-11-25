#include <stdio.h>
#include <string.h>
int d[101][101];
bool input(int &n)
{
	int m,x,y;
	memset(d,0x37,sizeof(d));
	scanf("%d",&n);
	if(!n)
		return false;
	for(int i = 1; i <= n; i++)
	{
		d[i][i] = 0;
		scanf("%d",&m);
		for(int j = 0; j < m; j++)
		{
			scanf("%d%d",&x,&y);
			d[i][x] = y;
		}
	}

	return true;
}
void floyd(int n)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
			{
				if(d[j][i] + d[i][k] < d[j][k])
					d[j][k] = d[j][i] + d[i][k];
			}
}
int main(int argc, char *argv[])
{
	int n,min,mini,max;
	while(input(n))
	{
		floyd(n);
		min = 0x37373737;
		mini = -1;
		for(int i = 1; i <= n; i++) {
			max = -1;
			for(int j = 1; j <= n; j++)
				if(max < d[i][j])
					max = d[i][j];
			if(min > max)
			{
				min = max;
				mini = i;
			}
		}
		if(mini == -1)
			puts("disjoint");
		else
			printf("%d %d\n",mini,min);
	}
	return 0;
}
