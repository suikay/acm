#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Tree
{
	int x,y;
	inline bool operator<(const Tree &b)const {
		if(y == b.y)
			return x > b.x;
		return y > b.y;
	}
};
Tree p[51000];
int main()
{
	int n,res;
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			return 0;
		res = 0;
		for(int i = 0; i < n; i++) 
			scanf("%d%d",&(p[i].x),&(p[i].y));
		sort(p,p+n);
		int now = -1*0x7fffffff;
		for(int i = 0; i < n; i++)
			if(p[i].x > now) {
				res++;
				now = p[i].x;
			}
		printf("%d\n",res);
	}

	return 0;
}