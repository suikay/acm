#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 11000;
int f[N];
bool v[N];
int p(int x)
{
	if(v[x])
		return x;
	v[x] = true;
	if(f[x] == -1)
		return 0;
	return p(f[x]);
}
int main()
{
	int k,n,x,y;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		memset(f,-1,sizeof(f));
		memset(v,false,sizeof(v));
		for(int i = 1; i < n; i++) {
			scanf("%d%d",&x,&y);
			f[y] = x;
		}
		scanf("%d%d",&x,&y);
		p(x);
		printf("%d\n",p(y));
	}


	return 0;
}