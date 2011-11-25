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
struct Status {
	int l,r;
};
Status st[20000];
int rec[20000];
bool v[20000];
int father[20000];
int bfs(int a,int b,int c)
{
	int top,end,tl,tr;
	top = end = 0;
	st[end].l = 0;
	father[end] = end;
	st[end++].r = 0;
	v[0] = true;
	while(top < end)
	{
		if(st[top].l == c || st[top].r == c)
			return top;
		tl = st[top].l;
		tr = st[top].r;
		if(tl != a && !v[150*a+tr]) {
			v[150*a+tr] = true;
			st[end].l = a;
			st[end].r = tr;
			father[end] = top;
			rec[end++] = 1;
		}
		if(tr != b && !v[150*tl+b]) {
			v[150*tl+b] = true;
			st[end].l = tl;
			st[end].r = b;
			father[end] = top;
			rec[end++] = 2;
		}
		if(tl != 0 && !v[tr]) {
			v[b] = true;
			st[end].l = 0;
			st[end].r = tr;
			father[end] = top;
			rec[end++] = 3;
		}
		if(tr != 0 && !v[150*tl]) {
			v[150] = true;
			st[end].l = tl;
			st[end].r = 0;
			father[end] = top;
			rec[end++] = 4;
		}
		int tmp;
		if(tl != a && tr != 0) {
			tmp = min(a-tl,tr);
			if(!v[(tl+tmp)*150+tr-tmp]) {
				v[(tl+tmp)*150+tr-tmp] = true;
				st[end].l = tl + tmp;
				st[end].r = tr - tmp;
				father[end] = top;
				rec[end++] = 5;
			}
		}
		if(tl != 0 && tr != b) {
			tmp = min(tl,b-tr);
			if(!v[(tl-tmp)*150+tr+tmp]) {
				v[(tl-tmp)*150+tr+tmp] = true;
				st[end].l = tl - tmp;
				st[end].r = tr + tmp;
				father[end] = top;
				rec[end++] = 6;
			}
		}
		top++;
	}
	return 0;
}


int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int sp[10000],end,now;
	now = bfs(a,b,c);
	end = 0;
	while(now != father[now]) {
		sp[end++] = now;
		now = father[now];
	}
	if(end == 0) {
		cout << "impossible" << endl;
		return 0;
	}
	string y;
	cout << end << endl;
	for(int i = end-1; i >= 0; i--) {
		switch(rec[sp[i]]) {
	case 1:
		y = "FILL(1)";
		break;
	case 2:
		y = "FILL(2)";
		break;
	case 3:
		y = "DROP(1)";
		break;
	case 4:
		y = "DROP(2)";
		break;
	case 5:
		y = "POUR(2,1)";
		break;
	default:
		y = "POUR(1,2)";
	}
		cout << y << endl;
	}

	return 0;
}