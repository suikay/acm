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
	int d[N],s[N],max[N],d2[N];
	int res(-999999);
	max[0]=d[0]=a[0];
	s[0]=0;
	for(int i = 1; i < n; i++) {
		if(d[i-1]>0) {
			d[i]=a[i]+d[i-1];
			s[i]=s[i-1];
		}
		else {
			d[i]=a[i];
			s[i]=i;
		}
		if(d[i]>max[i-1])
			max[i]=d[i];
		else
			max[i]=max[i-1];
	}
	for(int i = 0; i < n ;i++) {
		d2[i]=-1;
		for(int j = 1+i ;j < n; j++)
		{
			if(s[j]<i) {
				if(d2[j-1]>0)
					d2[j]=d2[j-1]+a[j];
				else
					d2[j]=a[j];
			}
			if(d2[j]+max[i]>res)
				res=d2[j]+max[i];
		}
	}
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