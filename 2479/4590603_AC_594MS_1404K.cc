#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define N 50050
int n,a[N];
void input()
{
	cin >> n;
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
	max2[n-1]=d2[n-1]=a[n-1];
	for(int i = n-2; i > 0; i--) {
		if(d2[i+1]>0)
			d2[i]=a[i]+d2[i+1];
		else
			d2[i]=a[i];
		if(d2[i]>max2[i+1])
			max2[i]=d2[i];
		else
			max2[i]=max2[i+1];
	}
	for(int i = 0; i < n-1; i++)
		if(res<(max[i]+max2[i+1]))
			res=max[i]+max2[i+1];
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		input();
		dp();
	}
	return 0;
}