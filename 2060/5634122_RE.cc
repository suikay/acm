#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 510;
int match[N],n,s[N],e[N];
bool v[N];
int first[N],next[N],ver[N],x[N],y[N],xx[N],yy[N];
int dis(int x,int y,int xx,int yy)
{
	return abs(x-xx)+abs(y-yy);
}
bool dfs(int x)
{
	for(int i = first[x];i > 0 ; i = next[i])
		if(!v[ver[i]]) {
			v[ver[i]] = true;
			if(match[ver[i]] == -1 || dfs(match[ver[i]])) {
				match[ver[i]] = x;
				return true;
			}
		}
	return false;
}

int MaxMatch()
{
	int cnt(0);
	memset(match,-1,sizeof(match));
	for(int i = 0; i < n; i++) {
		memset(v,false,sizeof(v));
		if(dfs(i))
			cnt++;
	}
	return cnt;
}

void input()
{
	int h,m,pn(1);
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d:%d%d%d%d%d",&h,&m,x+i,y+i,xx+i,yy+i);
		s[i] = h*60+m;
		e[i] = s[i] + dis(x[i],y[i],xx[i],yy[i]);
	}
	memset(first,0,sizeof(first));
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++) {
			if(s[j] <= e[i])
				break;
			if(s[j] <= (e[i] + dis(xx[i],yy[i],x[j],y[j])))
				continue;
			ver[pn] = j; next[pn] = first[i]; first[i] = pn++;
		}
}

int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		input();
		printf("%d\n",n-MaxMatch());
	}

	return 0;
}