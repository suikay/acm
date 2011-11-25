#include <iostream>
#include <stdio.h>
#include <string.h>
const int N(11000);
int arr[N];
bool v[N],ch;
using namespace std;
int loop(int x)
{
	if(arr[x] == 0)
		return -1;
	if(v[arr[x]])
		return x;
	v[x] = true;
	return loop(arr[x]);
}
void dfs(int x)
{
	ch = true;
	if(!arr[x])
		return ;
	dfs(arr[x]);
	printf("%d %d\n",x,arr[x]);
	arr[arr[x]] = arr[x];
}
int main()
{
	ch = false;
	int cnt,n,k,pt,last,tmp;
	scanf("%d%d",&n,&k);
	pt = 1;
	for(int i = 0; i < k; i++)
	{
		scanf("%d",&cnt);
		for(int j = 0; j < cnt; j++)
		{
			scanf("%d",&tmp);
			arr[tmp] = pt++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(arr[i] == i ||  arr[i] == 0)
			continue;
		memset(v,false,sizeof(v));
		if(loop(i) == -1)
		{
			dfs(i);
			arr[i] = 0;
		}
		else 
		{
			int j;
			for(j = n; j >= 1; j--)
				if(arr[j] == 0)
				break;
			last = arr[i];
			arr[i] = 0;
			printf("%d %d\n",i,j);
			dfs(last);
			printf("%d %d\n",j,last);
			arr[last] = last;
		}
	}
	if(!ch)
		cout << "No optimization needed"<< endl;
	return 0;
}