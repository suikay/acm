#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
set<int> ch[6];
map<int,int> pp;
bool v[300];
int x;
void f(int use)
{
	ch[use].insert(100000-x);
	if(use == 5)
		return;
	for(int i = 25; i >= 0; --i) {
		if(!v[i]) {
			v[i] = true;
			x |= (1 << i);
			f(use+1);
			x ^= (1 << i);
			v[i] = false;
		}else
			break;
	}
}
int change(string &xx)
{
	int res(0),now;
	for(int i = xx.size()-1; i >= 0; --i) {
		now =  (1 << (25-(xx[i]-'a')));
		if(now <= res || i == 5)
			return -1;
		res |= now;
	}
	return res;
}
int main()
{
	set<int>::iterator itr,en;
	f(0);
	int now = 1;
	for(int i = 1; i <= 5; i++)
		for(itr = ch[i].begin(),en=ch[i].end(); itr != en; itr++)
			pp[*itr] = now++;
	string p;
	while(cin >> p)
		cout << pp[100000-change(p)] << endl;
	
	return 0;
}