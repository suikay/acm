#include<memory.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n,w,a,b,mmin,mmax;
	char tmp;
	int arr[1001];
	scanf("%d",&n);
	while(n--)
	{
		memset(arr,0,sizeof(arr));
		scanf("%d\n",&w);
		mmin = 99999;
		mmax = -9999;
		for(int i = 0; i < w; i++){
			cin >> tmp >> a >> b;
			b--;
			if(a < mmin)
				mmin = a;
			if(b > mmax)
				mmax = b;
			for(int j = a; j <= b; j++)
				arr[j]++;
		}
		for(int i = mmin; i <= mmax; i++)
			if(arr[i])
				printf("%c",arr[i]+'A'-1);
		printf("\n");
	}
	return 0;
}
