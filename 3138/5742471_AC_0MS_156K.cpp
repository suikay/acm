#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int s,t,m;
bool v[110][3];
int main()
{
	int s,t,m,a,b,id,k(1);
	while(true) 
	{
		memset(v,false,sizeof(v));
		scanf("%d%d%d",&s,&t,&m);
		if(!s && !t && !m)
			return 0;
		for(int i = 0; i < s; i++) {
			scanf("%d%d%d",&id,&a,&b);
			if(a == 1)
				v[id][0] = true;
			if(b == 1)
				v[id][1] = true;
		}
		for(int i = 0; i < t; i++) {
			scanf("%d%d",&id,&a);
			if(a >= m)
				v[id][2] = true;
		}
		int cnt = 0;
		for(int i = 1; i <= s; i++)
			for(int j = 0; j < 3; j++)
				if(v[i][j])
					cnt++;
		printf("Case %d: %d\n",k++,cnt);
	}

	return 0;
}