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
int st[10000],rec[10000];
vector<int> relate[10000];
bool v[10000];
bool bp[10000];
int prime[2000],pn;
void init()
{
	pn = 0;
	for(int i = 2; i < 10000; i++)
		if(!bp[i]) {
			prime[pn++] = i;
			for(int j = i*i ; j < 10000; j+=i)
				bp[j] = true;
		}
		for(int i = 0; i < pn; i++) {
			if(prime[i] <= 1000)
				continue;
			for(int j = prime[i]/10*10; j < (prime[i]/10+1)*10; j++)
				if(!bp[j]) 
					relate[prime[i]].push_back(j);
			for(int j = prime[i]/100*100+prime[i]%10; j < (prime[i]/100*100+100); j+=10)
				if(!bp[j])
					relate[prime[i]].push_back(j);
			for(int j = prime[i]/1000*1000+prime[i]%100; j < (prime[i]/1000*1000+1000); j+=100)
				if(!bp[j])
					relate[prime[i]].push_back(j);
			for(int j = 1000 + prime[i]%1000; j < 10000; j += 1000)
				if(!bp[j])
					relate[prime[i]].push_back(j);
		}
}


int bfs(int a,int b)
{
	int top,end,tmp;
	top = end = 0;
	rec[end] = 0;
	st[end++] = a;
	while(top < end)
	{
		tmp = st[top];
		if(tmp == b)
			return rec[top];
		for(int i = 0; i < relate[tmp].size(); i++)
			if(!v[relate[tmp][i]]) {
				st[end] = relate[tmp][i];
				rec[end++] = rec[top] + 1;
				v[relate[tmp][i]] = true;
			}
			top ++;
	}
}

int main()
{
	int n;
	int a,b;
	init();
	cin >> n;
	while(n--) {
		memset(v,false,sizeof(v));
		cin >> a >> b;
		cout << bfs(a,b) << endl;
	}
	return 0;
}