#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 31;
bool v[N][N];
int son[N];
int ux[N],dx[N],uy[N],dy[N];
char block[N][N],x[N];
int pn;
void add(char x,char y)
{
	x -= 'A';
	y -= 'A';
	if(v[x][y] == true)
		return;
	v[x][y] = true;
	son[y]++;
}

void f(int last)
{
//	cout << " F " << last << endl;
	if(last == pn) {
		cout << x << endl;
		return;
	}
	for(int i = 0; i <= 26; i++)
		if(son[i] == 0) {
			for(int j = 0; j <= 26; j++)
				if(v[i][j])
					son[j]--;
			x[last] = 'A'+i;
			f(last+1);
			for(int j = 0; j <= 26; j++)
				if(v[i][j])
					son[j]++;
		}
}

bool input()
{
	static int _ux,_dx,_uy,_dy,x,y,tmp;
	static char ch;
	memset(son,-1,sizeof(son));
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	memset(ux,0x7f,sizeof(ux));
	memset(uy,0x7f,sizeof(uy));
	memset(v,false,sizeof(v));
	if(!(cin >> x >> y))
		return false;
	for(int i = 0; i < x; i++) {
		cin >> block[i];
		for(int j = 0; j < y; j++) {
			tmp = block[i][j] - 'A';
			if(i > dx[tmp])
				dx[tmp] = i;
			if(i < ux[tmp])
				ux[tmp] = i;
			if(j < uy[tmp])
				uy[tmp] = j;
			if(j > dy[tmp])
				dy[tmp] = j;
		}
	}
	pn = 0;
	for(int i = 0; i <= 26; i++)
		if(dx[i] != -1) {
			pn++;
			ch = i + 'A';
			_ux = ux[i];
			_dx = dx[i];
			_uy = uy[i];
			_dy = dy[i];
			for(int j = _ux; j <= _dx; j++) {
				add(ch,block[j][_uy]);
				add(ch,block[j][_dy]);
			}
			for(int j = _uy; j <= _dy; j++) {
				add(ch,block[_ux][j]);
				add(ch,block[_dx][j]);
			}
		}
	return true;
}

int main()
{
	while(input()) {
		x[pn] = '\0';
		f(0);
	}

	return 0;
}

/*
9
8
.CCC....
ECBCBB..
DCBCDB..
DCCC.B..
D.B.ABAA
D.BBBB.A
DDDDAD.A
E...AAAA
EEEEEE..
*/