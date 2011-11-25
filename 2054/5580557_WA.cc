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
const int N = 1100;
struct Node
{
	int f,w;
	bool operator<(const Node &x) const{
		return this->w > x.w;
	}
};
Node node[N];
int son[N];
int main()
{
	int n,r,sum,time,x,y;
	Node tmp;
	priority_queue<Node> qn;
	while(true)
	{
		scanf("%d%d",&n,&r);		
		sum = 0;
		time = n;
		if(!n && !r)
			return 0;
		for(int i = 1; i <= n; i++)
			scanf("%d",&(node[i].w));
		for(int i = 1; i < n; i++) {
			scanf("%d%d",&x,&y);
			node[y].f = x;
			son[x]++;
		}
		for(int i = 1; i <= n; i++)
			if(son[i] == 0)
				qn.push(node[i]);
		while(!qn.empty())
		{
			tmp = qn.top();
			qn.pop();
			sum += time*tmp.w;
			time--;
			son[tmp.f]--;
			if(son[tmp.f] == 0)
				qn.push(node[tmp.f]);
		}
		printf("%d\n",sum);
	}

	return 0;
}