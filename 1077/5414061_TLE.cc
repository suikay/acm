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
void sw(char &x,char &y) {
	char t = x;
	x = y;
	y = t;
}
map<string,bool> check;
string st[1000000];
int move[1000000],step[1000000],father[1000000];
int bfs(string ori)
{
	int top,end;
	int place,x,y;
	top = end = 0;
	st[end] = ori;
	father[end] = 0;
	end++;
	while(top < end) {
		if(st[top] == "12345678x")
			return top;
		place = find(st[top].begin(),st[top].end(),'x') - st[top].begin();
		x = place / 3;
		y = place % 3;
		if(x > 0 ) {
			sw(st[top][place],st[top][(x-1)*3+y]);
			if(check.count(st[top]) == 0) {
				check[st[top]] = true;
				st[end] = st[top];
				father[end] = top;
				move[end++] = 1;
			}
			sw(st[top][place],st[top][(x-1)*3+y]);
		}
		if(x < 2) {
			sw(st[top][place],st[top][(x+1)*3+y]);
			if(check.count(st[top]) == 0) {
				check[st[top]] = true;
				st[end] = st[top];
				father[end] = top;
				move[end++] = 2;
			}
			sw(st[top][place],st[top][(x+1)*3+y]);
		}
		if(y > 0) {
			sw(st[top][place],st[top][place-1]);
			if(check.count(st[top]) == 0) {
				check[st[top]] = true;
				st[end] = st[top];
				father[end] = top;
				move[end++] = 3;
			}
			sw(st[top][place],st[top][place-1]);
		}
		if(y < 2) {
			sw(st[top][place],st[top][place+1]);
			if(check.count(st[top]) == 0) {
				check[st[top]] = true;
				st[end] = st[top];
				father[end] = top;
				move[end++] = 4;
			}
			sw(st[top][place],st[top][place+1]);
		}
		top++;
	}
	return -1;
}



int main()
{
	char tmp;
	string x;
	for(int i = 0; i < 9; i++) {
		cin >> tmp;
		x.push_back(tmp);
	}
	int res = bfs(x);
	x = "";
	while(res != father[res])
	{
		switch(move[res]) {
			case 1:
				x.push_back('u');
				break;
			case 2:
				x.push_back('d');
				break;
			case 3:
				x.push_back('l');
				break;
			case 4:
				x.push_back('r');
				break;
		}
		res = father[res];
	}
	reverse(x.begin(),x.end());
	cout << x << endl;

	return 0;
}