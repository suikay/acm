#include<stdio.h>
#include<memory.h>
int xd[] = {-1, 0,1,0},yd[] = {0,1,0,-1};
int main()
{
	int w,h;
	int max,count;
	int x_tmp,y_tmp;
	char map[90][1100];
	scanf("%d%d\n",&h,&w);
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= h; j++)
			map[i][j] = getchar();
		getchar();
	}
	int queuex[100000],queuey[100000],top,res(0);
	for(int i = 1; i <= w; i++)
		for(int j = 1; j <= h; j++)
			if(map[i][j] == '*')
			{
				count = 0;
				queuex[top] = i;
				queuey[top++] = j;
				map[i][j] = '.';
				while(top){
					top--;
					count ++;
					x_tmp = queuex[top];
					y_tmp = queuey[top];
					for(int k = 0; k < 4; k++)
						if(map[x_tmp + xd[k]][y_tmp + yd[k]] == '*')
						{
							map[x_tmp + xd[k]][y_tmp + yd[k]] = '.';
							queuex[top] = x_tmp + xd[k];
							queuey[top++] = y_tmp + yd[k];
						}
				}
				max = max>count?max:count;
			}
	printf("%d\n",max);
	return 0;
}