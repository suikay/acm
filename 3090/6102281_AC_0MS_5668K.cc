#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
bool v[1010][1010];
int m[1010][1010];
int main()
{
	int t,n,cnt;
	memset(v,false,sizeof(v));
	v[0][0] = true;
	for(int i = 0; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(!v[i][j]) {
				cnt++;
				for(int k = 2; i*k <= 1000 && j*k <= 1000; k++)
					v[i*k][j*k] = true;
			}
	memset(m,0,sizeof(m));
	m[0][1] = 1;
	for(int i = 1; i <= 1000; i++)
		for(int j = 0; j <= 1000; j++)
			if(!v[i][j])
				m[i][j] = m[i-1][j]+1;
			else
				m[i][j] = m[i-1][j];
	for(int i = 1; i <= 1000; i++)
		for(int j = 0; j < i; j++)
			m[i][i] += m[i][j];
	scanf("%d",&t);
	for(int i = 1; i <= t; i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,m[n][n]);
	}
	
	return 0;
}
