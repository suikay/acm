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
int x[N],xx[N],y[N],yy[N],cnt[N];
vector<int> on[N],down[N];
bool use[N];
int main()
{
	int n,tx,ty,k(1);
	vector<int>qi;
	map<char,int>res;
	while(scanf("%d",&n) && n)
	{
		qi.resize(0);
		for(int i = 0; i < n; i++) {
			on[i].clear();
			down[i].clear();
		}
		memset(cnt,0,sizeof(cnt));
		memset(use,false,sizeof(use));
		res.clear();
		for(int i = 0; i < n; i++)
			scanf("%d%d%d%d",x+i,xx+i,y+i,yy+i);
		for(int i = 0; i < n; i++) {
			scanf("%d%d",&tx,&ty);
			for(int j = 0; j < n; j++)
				if(tx > x[j] && tx < xx[j] && ty > y[j] && ty < yy[j]) {
					cnt[i]++;
					down[j].push_back(i);
					on[i].push_back(j);
				}
		}
		for(int i = 0; i < n; i++) {
			if(cnt[i] == 1) 
				qi.push_back(i);
		}
		while(!qi.empty())
		{
			int now,top = qi.back();
			qi.pop_back();
			for(int i = 0; i < on[top].size(); i++) {
				now = on[top][i];
				if(use[now])
					continue;
				use[now] = true;
				res['A'+now] = 1+top;
				for(int j = 0; j < down[now].size(); j++) {
					cnt[down[now][j]]--;
					if(cnt[down[now][j]] == 1)
						qi.push_back(down[now][j]);
				}
			}
		}
		printf("Heap %d\n",k++);
		if(res.size() == 0)
			printf("none\n");
		else {
			map<char,int>::iterator itr = res.begin();
			while(itr != res.end())
			{
				printf("(%c,%d) ",itr->first,itr->second);
				++itr;
			}
		}
		printf("\n\n");
	}


	return 0;
}