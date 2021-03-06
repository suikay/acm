#include<memory.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 12522781
struct Point{
	int l,r;
	int diff;
	int next;
};
Point p[1000000];
int head[MAX];
int main()
{
	int arr[1000],n,ptr,max,sum,hash,i,j;
	while(true)
	{
		memset(p,0,sizeof(p));
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
				p[ptr].diff = arr[i] - arr[j];
				hash = abs(p[ptr].diff*2)%MAX;
				p[ptr].l = j;
				p[ptr].r = i;
				p[ptr].next = head[hash];
				head[hash] = ptr++;
			}
		for(i = n-1; i >= 0; i--)
			for(j = n-1; j > i; j--)
			{
				sum = arr[i] + arr[j];
				hash = abs(sum*2)%MAX;
				ptr = head[hash];
				while(ptr){
					if(sum == p[ptr].diff && p[ptr].l != j && p[ptr].l != i && max < p[ptr].r && p[ptr].r != i && p[ptr].r != j)
						max = p[ptr].r;
					ptr = p[ptr].next;
				}
			}
		if(max == -1)
			printf("no solution\n");
		else
			printf("%d\n",arr[max]);
	}
	return 0;
} 