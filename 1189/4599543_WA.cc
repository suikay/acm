#include<stdio.h>
#include <iostream>
using namespace std;
void print(int x,int y)	{
	if(!x)
		printf("0/1\n");
	else	{
		while(!(x%2))	{
			x/=2;
			y/=2;
		}
		printf("%d/%d\n",x,y);
	}
}
int main()
{
	int n,m;
	char c;
	bool ball[55][55];
	int record[55][55]={0};
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)	{
			cin >> c;
			ball[i][j] = (c=='*');
		}
	record[1][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i;j++)
			if(ball[i][j])	{
				record[i+1][j] += record[i][j];
				record[i+1][j+1] += record[i][j];
			}
			else
				record[i+2][j+1] += record[i][j]*4;
	int sum(0);
	for(int i  = 1; i <= n+1;i++)
		sum += record[n+1][i];
	print(record[n+1][m+1],sum);
	return 0;
}