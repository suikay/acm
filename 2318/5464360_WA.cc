#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 6000
int n,m,x1,x2,y1,y2;
struct Point {
	int u,d;
	bool operator()(Point a,Point b) {
		return a.u < b.u;
	}
};
Point ex[N];
int cal(int x1,int y1,int x2,int y2,int xp,int yp)
{
	return ((x2*y1-x2*yp+x1*yp-x1*y2)*1.0/(y1-y2)-xp)*1000;
}
int _find(int x,int y)
{
	int left,right,mid;
	left = 0;
	right = n+1;
	mid = (left + right) >> 1;
	while(left < right) {
		if(cal(ex[mid].u,y1,ex[mid].d,y2,x,y) > 0)
			right = mid;
		else
			left = mid + 1;
		mid = (left + right) >> 1;
	}
	if(cal(ex[mid].u,y1,ex[mid].d,y2,x,y) > 0)
		return mid-1;
	else
		return mid;
}
int main()
{
	int _count[N];
	int x,y;
	while(cin >> n && n)
	{
		memset(_count,0,sizeof(_count));
		cin >> m >> x1 >> y1 >> x2 >> y2;
		for(int i = 1; i <= n; i++)
			cin >> ex[i].u >> ex[i].d;
		ex[0].u = ex[0].d = x1;
		ex[n+1].u = ex[n+1].d = x2;
		sort(ex,ex+n+1,Point());
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			_count[_find(x,y)]++;
		}
		for(int i = 0; i <= n; i++)
			cout << i << ": " << _count[i] << endl;
		cout << endl;
	}
	return 0;
}