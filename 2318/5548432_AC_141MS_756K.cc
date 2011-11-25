#include<iostream>
#include<string.h>
#include<algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
const int N = 5500;
const double ESP = 10e-5;
int ux,x[N],dy,uy,cnt[N];
int n,m;
double k[N];
double cc(double kk)
{
	if(kk < 0) {
		return acos(-sqrt(1/(1+kk*kk)));
	}
	else {
		return acos(sqrt(1/(1+kk*kk)));
	}
}
int half(int xx,int yy)
{
	double kk;
	int left,right,mid;
	left = 0;
	right = n + 1;
	mid = (left + right) >> 1;
	while(left < right ) {
		kk = cc(1.0*(yy-dy)/(xx-x[mid]+ESP));
		if(kk > k[mid])
			right = mid;
		else
			left = mid+1;
		mid = (left + right) >> 1;
	}
	return mid;
}

int main()
{
//	freopen("2218.in","r",stdin);
	while(cin >> n)
	{
		if(!n)
			return 0;
		cin >> m;
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",x,&uy);
		scanf("%d%d",x+n+1,&dy);
		k[0] = cc(10e50);
		k[n+1] = k[0];
		for(int i = 1; i <= n; i++) {
			scanf("%d%d",&ux,x+i);
			k[i] = cc(1.0*(uy-dy)/(ux-x[i]+ESP));
		}
		int tmpx,tmpy;
		for(int i = 0; i < m; i++) { 
			scanf("%d%d",&tmpx,&tmpy);
			cnt[half(tmpx,tmpy)-1]++;
		}
		for(int i = 0; i <= n; i++)
			cout << i << ": " << cnt[i] << endl;
		cout << endl;
	}
	return 0;
}
 