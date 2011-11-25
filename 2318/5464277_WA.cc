#include<iostream>
#include<string.h>
using namespace std;
#define N 6000
int n,m,x1,x2,y1,y2;
int cal(int x1,int y1,int x2,int y2,int xp,int yp)
{
	return ((x2*y1-x2*yp+x1*yp-x1*y2)*1.0/(y1-y2)-xp)*1000;
}
int exu[N],exd[N];
int find(int x,int y)
{
	int left,right,mid;
	left = 0;
	right = n+1;
	mid = (left + right) >> 1;
	while(left < right) {
		if(cal(exu[mid],y1,exd[mid],y2,x,y) > 0)
			right = mid;
		else
			left = mid + 1;
		mid = (left + right) >> 1;
	}
	if(cal(exu[mid],y1,exd[mid],y2,x,y) > 0)
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
			cin >> exu[i] >> exd[i];
		exu[0] = exd[0] = x1;
		exu[n+1] = exd[n+1] = x2;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			_count[find(x,y)]++;
		}
		for(int i = 0; i <= n; i++)
			cout << i << ": " << _count[i] << endl;
	}
	return 0;
}