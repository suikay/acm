#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int N(30);
int x[N],xx[N],y[N],yy[N],_map[N][N],n,match[N];
bool v[N];

bool dfs(int x)
{
	for(int i = 0; i < n; i++) {
		if(!v[i] && _map[x][i]) {
			v[i] = true;
			if(match[i] == -1 || dfs(match[i])) { 
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 0; i < n; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

int main()
{
	int tx,ty,k(1);
	map<char,int>res;
	while(scanf("%d",&n) && n)
	{
		res.clear();
		memset(_map,0,sizeof(_map));
		for(int i = 0; i < n; i++)
			scanf("%d%d%d%d",x+i,xx+i,y+i,yy+i);
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&tx,&ty);
			for(int j = 0; j < n; j++)
				if(tx > x[j] && tx < xx[j] && ty > y[j] && ty < yy[j])
					_map[j][i] = 1;
		}
		int ori;
		ori = MaxMatch();
		for(int i = 0; i < n; i++) {
			int now,a = match[i];
			_map[a][i] = 0;
			now = MaxMatch();
			if(now != ori)
				res['A'+a] = i+1;
			_map[a][i] = 1;
			MaxMatch();
		}
		map<char,int>::iterator itr = res.begin();
		printf("Heap %d\n",k++);
		if(res.size() != 0)
			while(itr != res.end()) {
				printf("(%c,%d) ",itr->first,itr->second);
				itr++;
			}
		else
			printf("none");
		printf("\n\n");
	}
	


	return 0;
}