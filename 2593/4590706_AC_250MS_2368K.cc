#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define N 100050
int n,a[N];
int d[N],m2[N],m[N],d2[N];
bool input()
{
	scanf("%d",&n);
	if(!n)
		return false;
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	return true;
}
void dp()
{
	int res(-999999);
	m[0]=d[0]=a[0];
	for(int i = 1; i < n; i++) {
		if(d[i-1]>0)
			d[i]=a[i]+d[i-1];
		else
			d[i]=a[i];
		if(d[i]>m[i-1])
			m[i]=d[i];
		else
			m[i]=m[i-1];
	}
	m2[n]=d2[n]=-9999999;
	for(int i = n-1; i > 0; i--) {
		if(d2[i+1]>0)
			d2[i]=a[i]+d2[i+1];
		else
			d2[i]=a[i];
		if(d2[i]>m2[i+1])
			m2[i]=d2[i];
		else
			m2[i]=m2[i+1];
		if(res<(m[i-1]+m2[i]))
			res=m[i-1]+m2[i];
	}
	cout << res << endl;
}

int main()
{
	while(input()) 
		dp();
	return 0;
}