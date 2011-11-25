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
		return (this->x >= b.x  && this->xx <= b.xx && this->y >= b.y && this->yy <= b.yy);
	}
	inline bool operator()(const Rec &a,const Rec &b) {
		if(a.x == b.x)
			if(a.y == b.y)
				if(a.xx == b.xx)
					return a.yy > b.yy;
				else
					return a.xx > b.xx;
			else
				return a.y < b.y;
		return a.x < b.x;
	}
	inline bool operator<(const Rec &b) {
		if(this->x == b.x)
			if(this->y == b.y)
				if(this->xx == b.xx)
					return this->yy > b.yy;
				else
					return this->xx > b.xx;
			else
				return this->y < b.y;
		return this->x < b.x;
	}
	inline bool operator==(const Rec &b) {
		return memcmp(this,&b,sizeof(Rec)) == 0;
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
		sort(r,r+n,Rec());
		reverse(r,r+n);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(r[i].in(r[j])) {
					res++;
					if(r[i] == r[j]) {
						for(; j < n; j++)
							if(r[i] == r[j])
								res++;
						i = j;
						break;
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
*/
