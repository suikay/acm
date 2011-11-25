#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define N 50050
int n,a[N];
void input()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
}
void dp()
{
	int d[N],max2[N],max[N],d2[N];
	int res(-999999);
	max[0]=d[0]=a[0];
	for(int i = 1; i < n; i++) {
		if(d[i-1]>0)
			d[i]=a[i]+d[i-1];
		else
			d[i]=a[i];
		if(d[i]>max[i-1])
			max[i]=d[i];
		else
			max[i]=max[i-1];
	}
	max2[n]=d2[n]=-9999999;
	for(int i = n-1; i > 0; i--) {
		if(d2[i+1]>0)
			d2[i]=a[i]+d2[i+1];
		else
			d2[i]=a[i];
		if(d2[i]>max2[i+1])
			max2[i]=d2[i];
		else
			max2[i]=max2[i+1];
		if(res<(max[i-1]+max2[i]))
			res=max[i-1]+max2[i];
	}
	cout << res << endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		input();
		dp();
	}
	return 0;
}