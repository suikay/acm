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
string tmp;
map<string,bool> check;
int bfs(int n,string s1,string s2,string want)
{
	string tmp;
	int count(0);
	while(true)
	{
		tmp.clear();
		for(int i = 0; i < n; i++) {
			tmp += s2[i];
			tmp += s1[i];
		}
		if(tmp == want)
			return count+1;
		count++;
		if(check.count(tmp) > 0)
			return -1;
		check[tmp]=1;
		s1 = tmp.substr(0,n);
		s2 = tmp.substr(n,n);
	}
	return 0;
}
int main()
{
	int n,c;
	string a,b,want;
	cin >> n;
	for(int i= 1; i <= n; i++)
	{
		cin >> c >> a >> b >> want;
		cout << i << " " << bfs(c,a,b,want) << endl;
	}
	return 0;
}