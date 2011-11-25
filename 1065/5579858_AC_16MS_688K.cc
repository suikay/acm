#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Stick
{
	int l,w;
	bool operator()(const Stick &a,const Stick &b) {
		if(a.w == b.w)
			return a.l > b.l;
		return a.w > b.w;
	}
};
Stick stick[5100];
int main()
{
	int k,n,cnt,ll;
	bool v[5100];
	scanf("%d",&k);
	while(k--)
	{
		cnt = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) 
			scanf("%d%d",&(stick[i].l),&(stick[i].w));
		sort(stick,stick+n,Stick());
		memset(v,false,sizeof(v));
		for(int i = 0;i < n; i++) 
			if(!v[i])
			{
				ll = stick[i].l;
				cnt++;
				for(int j = i+1; j < n; j++)
					if(!v[j] && stick[j].l <= ll) {
						v[j] = true;
						ll = stick[j].l;
					}
			}
		printf("%d\n",cnt);
	}			

	return 0;
}