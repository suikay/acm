#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int rec[1050000];
int main()
{
	int t,mm,m,n,b,h,w,d,v,now;
	double res;
	scanf("%d",&t);
	while(t--)
	{
		memset(rec,0,sizeof(rec));
		mm = 1045000;
		m = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d%d",&b,&h,&w,&d);
			rec[b] += w*d;
			rec[b+h] -= w*d;
			m = max(m,b+h);
			mm = min(mm,b);
		}
		scanf("%d",&v);
		now = 0;
		for(int i = mm; i < m; i++) {
			now += rec[i];
			if(now >= v) {
				res = i + 1.0*v/now;
				v = -1;
				break;
			}
			v -= now;
		}
		if(v < 0)
			printf("%.2f\n",res);
		else
			puts("OVERFLOW");
	}
			

	return 0;
}
