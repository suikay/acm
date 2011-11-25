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
string rec[20000];
bool v[20000];
string bfs(int a,int b,int c)
{
	int top,end,tl,tr;
	top = end = 0;
	st[end].l = 0;
	st[end++].r = 0;
	v[0] = true;
	while(top < end)
	{
		if(st[top].l == c || st[top].r == c)
			return rec[top];
		tl = st[top].l;
		tr = st[top].r;
		if(tl != a && !v[150*a+tr]) {
			v[150*a+tr] = true;
			st[end].l = a;
			st[end].r = tr;
			rec[end++] = rec[top] + "1";
		}
		if(tr != b && !v[150*tl+b]) {
			v[150*tl+b] = true;
			st[end].l = tl;
			st[end].r = b;
			rec[end++] = rec[top] + "2";
		}
		if(tl != 0 && !v[tr]) {
			v[b] = true;
			st[end].l = 0;
			st[end].r = tr;
			rec[end++] = rec[top] + "3";
		}
		if(tr != 0 && !v[150*tl]) {
			v[150] = true;
			st[end].l = tl;
			st[end].r = 0;
			rec[end++] = rec[top] + "4";
		}
		int tmp;
		if(tl != a && tr != 0) {
			tmp = min(a-tl,tr);
			if(!v[(tl+tmp)*150+tr-tmp]) {
				v[(tl+tmp)*150+tr-tmp] = true;
				st[end].l = tl + tmp;
				st[end].r = tr - tmp;
				rec[end++] = rec[top] + "5";
			}
		}
		if(tl != 0 && tr != b) {
			tmp = min(tl,b-tr);
			if(!v[(tl-tmp)*150+tr+tmp]) {
				v[(tl-tmp)*150+tr+tmp] = true;
				st[end].l = tl - tmp;
				st[end].r = tr + tmp;
				rec[end++] = rec[top] + "6";
			}
		}
		top++;
	}
	return "";
}


int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	string x = bfs(a,b,c),y;
	cout << x.size() << endl;
	for(int i = 0; i < x.size(); i++) {
		switch(x[i]) {
	case '1':
		y = "FILL(1)";
		break;
	case '2':
		y = "FILL(2)";
		break;
	case '3':
		y = "DROP(1)";
		break;
	case '4':
		y = "DROP(2)";
		break;
	case '5':
		y = "POUR(2,1)";
		break;
	default:
		y = "POUR(1,2)";
	}
		cout << y << endl;
	}

	return 0;
}