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
int st[1000000],rec[1000000];
bool v[1000000];
int bfs(int n,int k)
{
	int top,end,tmp;
	top = end = 0;
	rec[end] = 0;
	st[end++] = n;
	while(top < end)
	{
		if(st[top] == k)
			return rec[top];
		tmp = st[top];
		v[tmp] = true;
		if(tmp >= 1 && !v[tmp-1]) {
			rec[end] = rec[top] + 1;
			st[end++] = tmp-1;
		}
		if(tmp < k) {
			if((tmp+1) < 1000000 && !v[tmp+1]) {
				rec[end] = rec[top] + 1;
				st[end++] = tmp+1;
			}
			if((2*tmp < 1000000 && !v[2*tmp])) {
				rec[end] = rec[top] + 1;
				st[end++] = tmp*2;
			}
		}
		top++;
	}
	return 0;
}

int main()
{
	int n,k;
	cin >> n >> k;
	cout << bfs(n,k) << endl;

	return 0;
}