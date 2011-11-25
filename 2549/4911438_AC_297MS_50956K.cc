#include<memory.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 10000000
#define M 1000000
int l[M],r[M];
int diff[M];
int next[M];
//Point p[1000000];
int head[MAX];
int main()
{
	int arr[1000],n,ptr,max,sum,hash,i,j;
	while(true)
	{
		memset(next,0,sizeof(next));
		memset(head,0,sizeof(head));
		ptr = 1;
		max = -1;
		scanf("%d",&n);
		if(!n)
			return 0;
		for(i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		if(n < 4){
			printf("no solution\n");
			continue;
		}
		sort(arr,arr+n);
		for(i = n-1; i >= 0;i--)
			for(j = n-1; j >= 0; j--)
			{
				if(i == j)
					continue;
				hash = abs(arr[i] - arr[j])%MAX;
				l[ptr] = j;
				r[ptr] = i;
				diff[ptr] = arr[i] - arr[j];
				next[ptr] = head[hash];
				head[hash] = ptr++;
			}
		for(i = n-1; i >= 0; i--)
			for(j = n-1; j > i; j--)
			{
				sum = arr[i] + arr[j];
				hash = abs(sum)%MAX;
				ptr = head[hash];
				while(ptr){
					if(sum == diff[ptr] && l[ptr] > j && max < r[ptr] && r[ptr] != i && r[ptr] != j){
						max = r[ptr];
						break;
					}
					else
						ptr = next[ptr];
				}
			}
		if(max == -1)
			printf("no solution\n");
		else
			printf("%d\n",arr[max]);
	}
	return 0;
}
