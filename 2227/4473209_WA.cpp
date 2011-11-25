#include <stdio.h>
#include <stdlib.h>
#define side(x,y) (x== 1 || y==1 || x==h || y==w)
typedef struct data{
	int x;
	int y;
	int height;
}data;
int d[305][305],sum;
bool colored[305][305];
data Data[1200];
int count;

int compare(const void *p1,const void *p2)
{//used by qiuck sort
	data a=*(data *)p1;
	data b=*(data *)p2;
	if(a.height >b.height )
		return 1;
	else
		return -1;
}

bool f(int x,int y,int height)
{
	bool flag = false;
	if( !colored[x][y]) {
		colored[x][y] = true;
		if( height > d[x][y] )
			sum += height - d[x][y];
		else {
			Data[count].x = x;
			Data[count].y = y;
			Data[count++].height = d[x][y];
			return true;
		}
	}
	if(!colored[x - 1][y] ) 
		flag |=f(x-1,y,height);
	if(!colored[x][y-1])
		flag |=f(x,y-1,height);
	if(!colored[x+1][y])
		flag |=f(x+1,y,height);
	if(!colored[x][y+1])
		flag |=f(x,y+1,height);
	return flag;
}

int main()
{
	int i,j,w,h;
	scanf("%d%d",&w,&h);
	for( i = 1; i <= h; i++)
		for( j = 1; j <= w; j++){
			scanf("%d",&d[i][j]);
			if(side(i,j)) {
			Data[count].x = i;
			Data[count].y = j;
			Data[count++].height = d[i][j];
			colored[i][j] = true;
			}
		}
		for( i = 0; i <= h; i++)
			colored[i][0] = colored[i][w + 1] = true;
		for( j = 0; j <= w; j++)
			colored[0][j] = colored[h+1][j] = true;
	qsort(Data,count,sizeof(data),compare);
	for( i = 0; i < count; i++)
		if(f(Data[i].x,Data[i].y,Data[i].height))
			qsort(Data + i,count - i,sizeof(data),compare);
	printf("%d",sum);
	return 0;
}

	