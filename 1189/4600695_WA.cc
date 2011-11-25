#include<stdio.h>
#include <iostream>
using namespace std;
long long gcd(__int64 x,__int64 y)	{
	if(x<y)
		swap(x,y);
	if(!(x%y))
		return y;
	return gcd(y,x%y);
}
void print(long long x,long long y)	{
	if(!x)
		printf("0/1\n");
	else	{
		printf("%lld/%lld\n",x/gcd(x,y),y/gcd(x,y));
	}
}
int main()
{
	int n,m;
	int i,j;
	char c,s[100];
	bool ball[60][60];
	long long record[60][60]={0};
	//cin >> n >> m;
	//freopen("hell","r",stdin);
	//freopen("out_2.txt","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(record,0,sizeof(record));
		getchar();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;)
			{
				scanf("%c",&c);
				if(c=='*' || c=='.')
				{
					ball[i][j]=(c=='*');
					j++;
				}
			}
			getchar();
		}
		record[1][1] = 1;
		for(i = 1; i <= n; i++)
			for(j = 1; j <= i;j++)
				if(ball[i][j])	{
					record[i+1][j] += record[i][j];
					record[i+1][j+1] += record[i][j];
				}
				else
					record[i+2][j+1] += record[i][j]*4;
		//long long sum(((long long)1)<<n);
		long long sum(0);
		for(i = 1; i <= n+1; i++)
			sum += record[n+1][i];
		print(record[n+1][m+1],sum);
	}
	return 0;
}