#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
struct Rec
{
	int x,y,xx,yy;
	inline bool in(const Rec &b) {
		return (x >= b.x && xx <= b.xx && y >= b.y && yy <= b.yy);
//		return (((x >= b.x && x < b.xx) || (xx > b.x && xx <= b.xx)) && \
//			((y >= b.y && y < b.yy) || (yy > b.y && yy <= b.yy)));
	}
	inline bool operator()(const Rec &a,const Rec &b) {
		if(a.x == b.x)
			if(a.y == b.y)
				if(a.xx == b.xx)
					return a.yy < b.yy;
				else
					return a.xx < b.xx;
			else
				return a.y > b.y;
		else
			return a.x > b.x;
	}
	inline bool operator<(const Rec &b) {
		if(this->x == b.x)
			if(this->y == b.y)
				if(this->xx == b.xx)
					return this->yy < b.yy;
				else
					return this->xx < b.xx;
			else
				return this->y > b.y;
		else
			return this->x > b.x;
	}
	inline bool operator==(const Rec &b) const{
		return (x == b.x && y == b.y && xx == b.xx && yy == b.yy);
	}
};
Rec r[5100];
bool v[5100];
int main()
{
	int n,res;
	while(scanf("%d",&n) == 1)
	{
		res = 0;
		for(int i = 0; i < n; i++)
			scanf("%d%d%d%d",&(r[i].x),&(r[i].xx),&(r[i].y),&(r[i].yy));
//		sort(r,r+n,Rec());
		memset(v,false,sizeof(v));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j && r[i].in(r[j])) {
					if(!v[i]) {
						v[i] = true;
						res++;
					}
				}
		printf("%d\n",res);
	}

	return 0;
}
/*
3
0 0 1 1
-5 10 -10 5
-10 5 5 10
2
0 1 0 1
0 1 0 2
2
0 2 0 1
0 1 0 1
2
-1 1 0 1
0 1 0 1
2
0 1 -1 1
0 1 0 1
5
0 2 1 2
1 2 0 2
1 2 1 3
1 3 1 2
1 2 1 2
*/
