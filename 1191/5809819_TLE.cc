#include <stdio.h>
#include <string.h>
#include <math.h>
const int M = 10;
int tmp,s[M][M][M][M],m[M][M];
int dp[M][M][M][M][15];
inline int min(const int a,const int b) {
	return (a>b)?b:a;
}
inline int SQ(const int &a)  {
	return a*a;
}
inline double SQ(const double &b) {
	return b*b;
}
void sum()
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++) 
			for(int ii = i+1; ii <= 8; ii++) {
				tmp = 0;
				for(int jj = j+1; jj <= 8; jj++) {
					tmp += m[ii][jj];
					s[i][j][ii][jj] = s[i][j][ii-1][jj] + tmp;
				}
			}
	memset(dp,-1,sizeof(dp));
}

int dfs(int x,int y,int xx,int yy,int d)
{
	if(d == 1)
		return SQ(s[x][y][xx][yy]);
	if(dp[x][y][xx][yy][d] >= 0)
		return dp[x][y][xx][yy][d];
	int res(10000000);
	for(int i = x+1; i < xx; i++)
		res = min(res,min(dfs(x,y,i,yy,d-1)+dfs(i,y,xx,yy,1),dfs(i,y,xx,yy,d-1)+dfs(x,y,i,yy,1)));
	for(int i = y+1; i < yy; i++)
		res = min(res,min(dfs(x,y,xx,i,d-1)+dfs(x,i,xx,yy,1),dfs(x,i,xx,yy,d-1)+dfs(x,y,xx,i,1)));
	if(res == 10000000)
		dp[x][y][xx][yy][d] = -1;
	else
		dp[x][y][xx][yy][d] = res;
	return res;
}

int main()
{
	int n;
	double res;
	scanf("%d\n",&n);
	for(int i = 1; i <= 8; i++)
		for(int j = 1; j <= 8; j++)
			scanf("%d",&(m[i][j]));
	sum();
	double ave = ((double)s[0][0][8][8])/n;
	res = dfs(0,0,8,8,n);
	printf("%.3f\n",sqrt(((double)res)/n-SQ(ave)));
	return 0;
}
/*
2
100 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

*/
