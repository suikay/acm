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
	while(cin >> h >> w) {
		memset(lux,0x07,sizeof(lux));
		memset(luy,0x07,sizeof(luy));
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
				if(lux[m[i][j]-'A'] > i)
					lux[m[i][j]-'A'] = i;
				if(luy[m[i][j]-'A'] > j)
					luy[m[i][j]-'A'] = j;
				if(rdx[m[i][j]-'A'] < i)
					rdx[m[i][j]-'A'] = i;
				if(rdy[m[i][j]-'A'] < j)
					rdy[m[i][j]-'A'] = j;
			}
		bool v[30];
		memset(v,false,sizeof(v));
		string res;
		for(int i = 0; i < 26; i++)
			if(rdx[i] != -1)
				type++;
		bool path[200][200];
		memset(path,false,sizeof(path));
		int cou[200];
		memset(cou,-1,sizeof(cou));
			for(int j = 'Z'; j >= 'A'; j--)
				if(rdx[j-'A'] != -1)
					for(int k = lux[j-'A']; k <= rdx[j-'A']; k++)
						for(int l = luy[j-'A'] ; l <= rdy[j-'A']; l++) {
							if(k > lux[j-'A'] && k < rdx[j-'A'] && l > luy[j-'A'] && l < rdy[j-'A'])
								continue;
							if(path[j][m[k][l]] == false) {
								path[j][m[k][l]] = true;
								cou[j]++;
							}
						}
	for(int k = 0; k < 26; k++)
		for(int i = 'Z'; i >= 'A'; i--)
			if(cou[i] == 0) {
				res.push_back(i);
				for(int j = 'A'; j <= 'Z'; j++)
					if(path[j][i]) {
						path[j][i] = false;
						cou[j]--;
					}
			}
				
		reverse(res.begin(),res.end());
		cout << res << endl;
	}
	return 0;
}