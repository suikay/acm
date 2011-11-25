#include <stdio.h>
#include <algorithm>
using namespace std;
struct Hotel
{
	int dis,esp;
	bool operator()(const Hotel &a,const Hotel &b)
	{
		if(a.dis == b.dis)
			return a.esp < b.esp;
		return a.dis < b.dis;
	}
};
Hotel h[11000];
int main()
{
	int n,cheap,dear,res;
	while(scanf("%d",&n) && n) 
	{
		res = 0;
		for(int i = 0; i < n; i++)
			scanf("%d%d",&(h[i].dis),&(h[i].esp));
		sort(h,h+n,Hotel());
		cheap = h[0].esp + 1;
		for(int i = 0; i < n; i++)
			if(cheap > h[i].esp) 
			{
//				printf("%d\n",i);
				cheap = h[i].esp;
				res++;
			}
		printf("%d\n",res);
	}
	return 0;
}

				