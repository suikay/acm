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
int l[20],r[20],ln,rn,n;
int m[20][20],res;
void dfs(int now,int z)
{
	if(now == n) {
		if(z > res)
			res = z;
		return;
	}
	int tmp(0);
	for(int i = 0; i < rn; i++)
		tmp += m[now][r[i]];
	l[ln++] = now;
	dfs(now+1,z+tmp);
	tmp = 0;
	ln--;
	for(int i = 0; i < ln; i++)
		tmp += m[now][l[i]];
	r[rn++] = now;
	dfs(now+1,z+tmp);
	rn--;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[i][j];
	dfs(0,0);
	cout << res << endl;
	return 0;
}