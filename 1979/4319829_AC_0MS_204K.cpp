#include <stdio.h>
#include <memory.h>
int w,h;
char home[21][21];
int f(int x,int y)
{
	if (x >= h || x < 0 || y >= w || y < 0)
		return 0;
	if (home[x][y] != '.')
		return 0;
	home[x][y] = '#';
	return 1 + f(x+1,y) + f(x-1,y) + f(x,y+1) + f(x,y-1);
}
int main()
{
	bool flag;
	int i,j;
	scanf("%d%d",&w,&h);
	while( w > 0)
	{
		flag = true;
		getchar();
		for ( i = 0 ; i < h ; i ++)
			gets(home[i]);
		for ( i = 0 ; i < h && flag; i++)
			for ( j = 0 ; j < w; j++)
				if (home[i][j] == '@') {
					home[i][j] = '.';
					printf("%d\n",f(i,j));
					flag = false;
					break;
				}
		scanf("%d%d",&w,&h);
	}
	return 0;
}