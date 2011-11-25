#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int M=13107101;
bool v[M];
int st[3000000][15];
int step[3000000];
int want_hash,want_hash2;
void swap(int *x,int start,int mid,int end,int len)
{
	static int tmp[20];
	int i,n(0);
	memset(tmp,0,sizeof(tmp));
	for(i = 0; i < start; i++)
		tmp[n++] = x[i];
	for(i = mid+1; i <= end; i++)
		tmp[n++] = x[i];
	for(i = start; i <= mid; i++)
		tmp[n++] = x[i];
	for(i = end+1; i < len; i++)
		tmp[n++] = x[i];
	memcpy(x,tmp,sizeof(tmp));
}
int hash(const int *x,int len,int& h2)
{
	unsigned long h(0),g;
	h2 = 0;
	while(len > 0) {
		h = (h << 4) + x[--len];
		h2 = h2*13 + x[len];
		g = h & 0xf0000000l;
		if(g)
			h ^= g >> 24;
		h &= ~g;
	}
	if(h2 == 0)
		h2 = -131;
	return h % M;
}
int bfs(int *x,int len)
{
	int top,end;
	int i,j,k,h,h2;
	top = end = 0;
	for(i = 0; i < len; i++)
		st[0][i] = x[i];
	step[end++] = 0;
	while(top < end)
	{
		for(i = 0; i < len; i++)
			for(j = i; j < len; j++)
				for(k = 1; k+j < len; k++) {
					memcpy(st[end],st[top],15*sizeof(int));
					swap(st[end],i,j,j+k,len);
					h = hash(st[end],len,h2);
					if(h == want_hash && h2 == want_hash2)
						return step[top] + 1;
					while(v[h] && v[h] != want_hash2) {
						h++;
						if(h == M)
							h = 0;
					}
					if(v[h] || step[top] >= 3)
						continue;
					v[h] = h2;
					step[end++] = step[top] + 1;
				}
		top++;
	}
	return 5;
}
int main()
{
	int c,n,ori[15],move,h2;
	scanf("%d",&c);
	while(c--) {
		memset(v,false,sizeof(v));
		memset(step,0,sizeof(step));
		memset(st,0,sizeof(st));
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			ori[i] = i+1;
		want_hash = hash(ori,n,want_hash2);
		for(int i = 0; i < n; i++)
			scanf("%d",ori+i);
		if(hash(ori,n,h2) == want_hash)
			if(h2 == want_hash2)
				move = 0;
			else
				move = bfs(ori,n);
		else
			move = bfs(ori,n);
		if(move == 5)
			printf("5 or more\n");
		else
			printf("%d\n",move);
	}
	return 0;
}
					