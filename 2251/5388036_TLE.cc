/*
ID: immozer1
PROG: ****
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
#define N 35
int dl[] = {0,0,0,0,1,-1};
int dr[] = {1,-1,0,0,0,0};
int dc[] = {0,0,-1,1,0,0};
int L,R,C,res;
bool v[N][N][N];
char m[N][N][N];
void dfs(int l,int r,int c,int t)
{
	int tl,tr,tc;
	if(t >= res)
		return;
	if(m[l][r][c] == 'E' )
		res = t;
	for(int i = 0; i < 8; i++) {
		tl = l + dl[i];
		tr = r + dr[i];
		tc = c + dc[i];
		if(tl >= 0 && tl < L && tc >= 0 && tc < C 
			&& tr >= 0 && tr < R && m[tl][tr][tc] != '#'
			&& !v[tl][tr][tc])
		{
			v[tl][tr][tc] = true;
			dfs(tl,tr,tc,t+1);
			v[tl][tr][tc] = false;
		}
	}
}
int main()
{
	int sl,sr,sc;
	while(scanf("%d%d%d",&L,&R,&C) && L)
	{
		res = 9999999;
		for(int i = 0; i < L; i++)
			for(int j = 0; j < R; j++) {
				cin >> m[i][j];
				for(int k = 0; k < C; k++)
					if(m[i][j][k] == 'S') {
						sl = i;
						sr = j;
						sc = k;
					}
			}
		dfs(sl,sr,sc,0);
		if(res != 9999999)
			printf("Escaped in %d minute(s).\n",res);
		else
			cout << "Trapped!\n" << endl;
	}
	return 0;
}