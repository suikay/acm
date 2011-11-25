#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;
#define M 110
char map[M][M];
int main()
{
	int m,n,res,xx,yy;
	int i,j,k;
	char ch;
	int x[8] = {-1,-1,-1,0,1,1,1,0},y[8] = {-1,0,1,1,1,0,1,1};
	int qx[10010],qy[1100],top;
	while(scanf("%d%d",&m,&n)&&m)
	{
		top = 0;
		res = 0;
		memset(map,0,sizeof(map));
		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++){
				cin >> ch;
				if(ch == '@')
					map[i][j] = 1;
			}
		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				if(map[i][j]){
					res++;
					qx[top] = i;
					qy[top++] = j;
					while(top)
					{
						top--;
						xx = qx[top];
						yy = qy[top];
						map[xx][yy] = 0;
						for(k = 0; k < 8; k++)
							if(map[xx+x[k]][yy+y[k]])	{
								qx[top] = xx + x[k];
								qy[top++] = yy + y[k];
							}
					}
				}
		printf("%d\n",res);
	}
	return 0;
}