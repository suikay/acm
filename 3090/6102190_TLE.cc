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
int main()
{
	int t,n,cnt;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++)
	{
		memset(v,false,sizeof(v));
		v[0][0] = true;
		cnt = 0;
		scanf("%d",&n);
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				if(!v[j][k]) {
					cnt++;
					for(int l = 2; j * l <= n && k * l <= n; l++)
						v[j*l][k*l] = true;
				}
		printf("%d %d %d\n",i,n,cnt);
	}		

	return 0;
}
