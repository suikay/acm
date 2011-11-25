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
set<string> ch[6];
map<string,int> pp;
bool v[300];
char x[30];
void f()
{
	int sz = strlen(x);
	ch[sz].insert(x);
	if(sz == 5)
		return;
	for(int i = 'z'; i >= 'a'; --i) {
		if(!v[i]) {
			v[i] = true;
			x[sz] = i;
			x[sz+1] = '\0';
			f();
			x[sz] = '\0';
			v[i] = false;
		}else break;
	}
}
int main()
{
	set<string>::iterator bg,itr;
	x[0] = '\0';
	f();
	int now = 1;
	for(int i = 1; i <= 5; i++)
		for(itr = ch[i].begin(),bg = ch[i].end(); itr != bg; ++itr)
			pp[*itr] = now++;
	string p;
	while(cin >> p)
		cout << pp[p] << endl;
	
	return 0;
}