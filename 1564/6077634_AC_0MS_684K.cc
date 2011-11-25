#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int t, n, arr[12];
bool check;
bool input()
{
	scanf("%d%d",&t,&n);
	if(!t && !n)
		return false;
	for(int i = 0 ; i < n; i++)
		scanf("%d",&arr[i]);
	return true;
}

void dfs(int now,int sum,int step)
{
	//cout << "DFS " << now << " " << sum << " " << step << endl;
	if(sum == t) {
		bool flag = false;
		for(int i = 0; i < n; i++)
			if(step & (1 << i)) {
				if(!flag)
					flag = true;
				else
					putchar('+');
				printf("%d",arr[i]);
			}
		putchar('\n');
		check = true;
		return;
	}
	if(sum > t || now >= n)	return;
	if(now == 0 || arr[now] != arr[now-1] || (step & (1 << (now-1))))
		dfs(now+1,sum+arr[now],step|(1 << now));
	dfs(now+1,sum,step);
	return;
}

int main()
{
	while(input())
	{
		check = false;
		printf("Sums of %d:\n",t);
		dfs(0,0,0);
		if(!check)
			puts("NONE");
	}


	return 0;
}
