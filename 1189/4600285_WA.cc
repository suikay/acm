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
	long long n,m;
	char c,s[100];
	bool ball[55][55];
	long long record[55][55]={0};
	cin >> n >> m;
	memset(record,0,sizeof(record));
	for(long long i = 1; i <= n; i++)	{
		for(int j = 1; j <= i; j++)	{
			cin >> c;
			ball[i][j] = (c == '*');
		}
		gets(s);
	}
	record[1][1] = 1;
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= i;j++)
			if(ball[i][j])	{
				record[i+1][j] += record[i][j];
				record[i+1][j+1] += record[i][j];
			}
			else
				record[i+2][j+1] += record[i][j]*4;
	//long long sum(((long long)1)<<n);
	long long sum(0);
	for(int i = 1; i <= n+1; i++)
		sum += record[n+1][i];
	print(record[n+1][m+1],sum);
	return 0;
}