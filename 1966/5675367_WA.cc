#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 60;
int cnt[N],st[N*N],n,m,most[N];
bool road[N][N],v[N][N],in[N];
int bfs(int ori)
{
	int top,end,now;
	memset(v,false,sizeof(v));
	memset(in,false,sizeof(in));
	memset(cnt,0,sizeof(cnt));
	top = end = 0;
	st[end++] = ori;
	in[ori] = true;
	cnt[ori] = 0;
	while(top < end) {
		now = st[top++];
		for(int i = 0; i < n; i++)
			if(road[now][i] != v[now][i]) {
				v[now][i] = true;
				cnt[i]++;
				if(!in[i]) {
					in[i] = true;
					st[end++] = i;
				}
			}
	}
//	for(int i = 0; i < n; i++)
//		cout << cnt[i] << " " ;
//	cout << endl;
	sort(cnt,cnt+n);
	return cnt[0];
}

bool input()
{
	char tmp;
	int x,y;
	if(scanf("%d%d",&n,&m) != 2)
		return false;
	memset(road,false,sizeof(road));
	for(int i = 0; i < m; i++) {
		cin >> tmp >> x >> tmp >> y >> tmp;
		road[x][y] = road[y][x] = true;
	}
	return true;
}

int main()
{
	int tmp,res;
	while(input()) {
		res = n;
		for(int i = 0; i < n; i++) {
			tmp = bfs(0);
			if(tmp < res)
				res = tmp;
		}
		if(res == n-1)
			cout << n << endl;
		else
			cout << res << endl;
	}

	return 0;
}