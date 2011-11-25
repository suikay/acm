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
char m[35][35];
int h,w;
bool check(int lux,int luy,int rdx,int rdy,char x)
{
	for(int i = lux; i <= rdx; i++)
		for(int j = luy; j <= rdy; j++) {
			if(i > lux && i < rdx && j > luy && j < rdy)
				continue;
			if(m[i][j] != x && m[i][j] != ' ')
				return false;
		}
	for(int i = lux; i <= rdx; i++)
		for(int j = luy; j <= rdy; j++) {
			if(i > lux && i < rdx && j > luy && j < rdy)
				continue;
			m[i][j] = ' ';
		}
	return true;
}
int main()
{
	int lux[30],luy[30],rdx[30],rdy[30];
	cin >> h >> w;
	memset(lux,-1,sizeof(lux));
	memset(luy,-1,sizeof(luy));
	memset(rdx,-1,sizeof(rdx));
	memset(rdy,-1,sizeof(rdy));
	int type(0);
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) {
			cin >> m[i][j];
			if(m[i][j] == '.') {
				m[i][j] = ' ';
				continue;
			}
			if(lux[m[i][j]-'A'] == -1) {
				type++;
				lux[m[i][j]-'A'] = i;
			}
			if(luy[m[i][j]-'A'] == -1)
				luy[m[i][j]-'A'] = j;
			if(rdx[m[i][j]-'A'] < i)
				rdx[m[i][j]-'A'] = i;
			if(rdy[m[i][j]-'A'] < j)
				rdy[m[i][j]-'A'] = j;
		}
	bool v[30];
	memset(v,false,sizeof(v));
	string res;
	for(int i = 0; i < type; i++)
		for(int j = 0; j < 26; j++)
			if(!v[j] && lux[j] != -1)
				if(check(lux[j],luy[j],rdx[j],rdy[j],j+'A')) {
					v[j] = true;
					res.push_back('A'+j);
					break;
				}
	reverse(res.begin(),res.end());
	cout << res << endl;

	return 0;
}