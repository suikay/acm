#include<stdio.h>
int deep,num[101][101];
int f(int x,int y)
{
	int left,right;
	if (x==deep-1)
		return num[x][y];
		left=f(x+1,y),right=f(x+1,y+1);
	return num[x][y]+(left>right?left:right);
}
void main()
{
	int i,j;
	scanf("%d",&deep);
	for(i=0;i<deep;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&num[i][j]);
	printf("%d",f(0,0));
}