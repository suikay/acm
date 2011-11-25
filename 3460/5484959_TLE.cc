#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int M=1317101;
int want_hash,want_hash2,res;
char des[15];
char tmp[20];
void swap(char *x,int start,int mid,int end,int len)
{
	int i,n(0);
	memset(tmp,0,15);
	for(i = 0; i < start; i++)
		tmp[n++] = x[i];
	for(i = mid+1; i <= end; i++)
		tmp[n++] = x[i];
	for(i = start; i <= mid; i++)
		tmp[n++] = x[i];
	for(i = end+1; i < len; i++)
		tmp[n++] = x[i];
	memcpy(x,tmp,15);
}
int hash(const char *x,int len,int& h2)
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
void dfs(char *x,int len,int steps)
{
	int i,j,k;
	char tmp[15];
	if(steps > 4 || steps >= res)
		return;
	for(i = 0; i < len; i++)
		if(x[i] != des[i])
			break;
	if(i == len && res > steps) {
		res = steps;
		return;
	}
	for(int i = 0; i < len; i++)
		for(int j = i; j < len; j++)
			for(int k = 1; j+k < len; k++)
			{
				memcpy(tmp,x,sizeof(tmp));
				swap(tmp,i,j,j+k,len);
				dfs(tmp,len,steps+1);
			}
}

int main()
{
	int c,n,move,h2;
	char ori[15];
	scanf("%d",&c);
	while(c--) {
		//memset(v,false,sizeof(v));
		//memset(step,0,sizeof(step));
		//memset(st,0,sizeof(st));
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			des[i] = i+1;
		/*want_hash = hash(ori,n,want_hash2);*/
		for(int i = 0; i < n; i++)
			scanf("%d",ori+i);
		//if(hash(ori,n,h2) == want_hash)
		//	if(h2 == want_hash2)
		//		move = 0;
		//	else
		//		move = bfs(ori,n);
		//else
		//	move = bfs(ori,n);
		//if(move == 5)
		//	printf("5 or more\n");
		//else
		//	printf("%d\n",move);
		res = 5;
		dfs(ori,n,0);
		if(res == 5)
			printf("5 or move\n");
		else
			printf("%d\n",res);
	}
	return 0;
}


//int bfs(char *x,int len)
//{
//	int top,end;
//	int i,j,k,h,h2;
//	top = end = 0;
//	for(i = 0; i < len; i++)
//		st[0][i] = x[i];
//	step[end++] = 0;
//	while(top < end)
//	{
//		for(i = 0; i < len; i++)
//			for(j = i; j < len; j++)
//				for(k = 1; k+j < len; k++) {
//					memcpy(st[end],st[top],15*sizeof(int));
//					swap(st[end],i,j,j+k,len);
//					h = hash(st[end],len,h2);
//					if(h == want_hash && h2 == want_hash2)
//						return step[top] + 1;
//					while(v[h] && v[h] != want_hash2) {
//						h++;
//						if(h == M)
//							h = 0;
//					}
//					if(v[h] || step[top] >= 3)
//						continue;
//					v[h] = h2;
//					step[end++] = step[top] + 1;
//				}
//		top++;
//	}
//	return 5;
//}