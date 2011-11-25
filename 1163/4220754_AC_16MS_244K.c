#include<stdio.h>
int deep,num[101][101],rec[100][100];
void main()
{
	int i,j;
	scanf("%d",&deep);
	for(i=0;i<deep;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&num[i][j]);
	for(i=deep-1;i>0;i--)
		for(j=0;j<i;j++)
			if (num[i][j]>num[i][j+1])
				num[i-1][j]+=num[i][j];
			else
				num[i-1][j]+=num[i][j+1];
	printf("%d",num[0][0]);
}
