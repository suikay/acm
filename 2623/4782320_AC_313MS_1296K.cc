#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	unsigned int arr[250010];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%u",&arr[i]);
	sort(arr,arr+n);
	if(n%2)
		printf("%u.0\n",arr[n/2]);
	else
		printf("%.1f\n",0.5*arr[(n-1)/2]+0.5*arr[n/2]);
	return 0;
}