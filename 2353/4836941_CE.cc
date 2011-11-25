#include<memory.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int rooms[105][505];
long long ttime[105][505];
int m,n;
int len[105][505];
int path[105][505];
int main()
{
	scanf("%d%d",&m,&n);
	int tmp;
	for(int i = 1; i <= m; i++)	{
		tmp = 0;
		ttime[i][0] = 0;
		for(int j = 1;j <= n; j++)	{
			scanf("%d",&rooms[i][j]);
			tmp += rooms[i][j];
			len[i][j] = tmp;
		}
	}
	memset(ttime,0x7f,sizeof(ttime));
	memset(ttime,0,sizeof(ttime)/105*2);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)	{
			for(int k = 1; k <= j;k++)
				if(ttime[i+1][k] > (ttime[i][j] + len[i][j] - len[i][k-1]))	{
					path[i+1][k] = j;
					ttime[i+1][k] = ttime[i][j] + len[i][j] - len[i][k-1];
				}
			for(int k = j+1; k<= n;k++)
				if(ttime[i+1][k] > (ttime[i][j] + len[i][k] - len[i][j-1]))	{
					path[i+1][k] = j;
					ttime[i+1][k] = ttime[i][j] + len[i][k] - len[i][j-1];
				}
			ttime[i][j] += rooms[i][j];
		}

	long long res(0x7fffffffffff);
	int pos;
	for(int i = 1; i <= n; i++)
		if(res > ttime[m][i]){
			res = ttime[m][i];
			pos = i;
	}
	int queue[200],top(0);
	queue[top++] = pos;
	for(int i = m-1; i >= 0; i--)	{
		pos = path[i+1][pos];
		queue[top++] = pos;
	}
	for(int i = top-1; i > 0; i--)	{
		if(queue[i] != queue[i-1])	{
			if(queue[i] > queue[i-1])
				for(int j = queue[i] ; j >= queue[i-1]; j--)
					printf("%d\n",j);
			else
				for(int j = queue[i-1]; j <= queue[i]; j++)
					printf("%d\n",j);
		}
		else
			printf("%d\n",queue[i]);
	}
	printf("%d\n",queue[0]);
	return 0;
}