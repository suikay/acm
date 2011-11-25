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
int n,col[30],ad[30][30],adc[30],res;
int coun[4];
void dfs(int now)
{
	int tmp(0);
	if(now == n) {
		for(int i = 0; i < 4; i++)
			if(coun[i] != 0)
				tmp++;
		if(tmp < res )
			res = tmp;
		return;
	}
	int j;
	for(int i = 0; i < 4; i++) {
		for( j = 0; j < adc[now]; j++)
			if(col[ad[now][j]] == i) 
				break;
		if(j == adc[now]) {
			col[now] = i;
			coun[i]++;
			dfs(now+1);
			coun[i]--;
		}
	}
}
int main()
{
	string x;
	int id;
	while(cin >> n)
	{
		res = 4;
		memset(col,-1,sizeof(col));
		memset(adc,0,sizeof(adc));
		memset(coun,0,sizeof(coun));
		if(n == 0)
			return 0;
		for(int i = 0 ; i < n; i++)
		{
			cin >> x;
			id = x[0] - 'A';
			adc[id] = x.size() - 2;
			for(int j = 2; j < x.size(); j++)
				ad[id][j-2] = x[j] - 'A';
		}
		dfs(0);
		printf("%d channel%s needed.\n",res,res>1?"s":"");
	}
	return 0;
}