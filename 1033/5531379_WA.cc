#include <stdio.h>
#include <string.h>
const int N = 11000;
int arr[N],n;
bool ch,v[N];
int loop(int m)
{
	memset(v,false,sizeof(v));
	int now = m;
	do
	{
		v[now] = true;
		if(v[arr[now]])
			return now;
		now = arr[now];
		if(now == 0)
			break;
	}
	while (true);
	return 0;
}
int dfs(int m)
{
	int last;
	ch = true;
	if(arr[m] == 0 || v[arr[m]])
		return m;
	v[m] = true;
	printf("%d %d\n",arr[m],m);
	last = dfs(arr[m]);
	arr[m] = m;
	return last;
}
int main()
{
	int n,k,pt,last,j;
	scanf("%d%d",&n,&k);
	pt = 1;
	ch = false;
	for(int i = 0; i < k; i++) {
		scanf("%d",&n);
		for(int j = 0; j < n; j++) 
			scanf("%d",&(arr[pt++]));
	}
	for(int i = 1; i < pt; i++) {
		if(arr[i] == i)
			continue;
		if((last = loop(i))== 0) {
			memset(v,false,sizeof(v));
			arr[dfs(i)] = 0;
		}
		else {
			for(j = 1; j < pt; j++)
				if(arr[j] == 0)
					break;
			printf("%d %d\n",i,j);
			memset(v,false,sizeof(v));
			last = dfs(i);
			printf("%d %d\n",j,last);
			arr[last] = last;
		}
	}
	if(!ch)
		printf("No optimization needed\n");
	return 0;
}


