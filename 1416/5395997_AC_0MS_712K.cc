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
int res,rc,num[20],n;
string rec,pig;
void dfs(int now,int z,int last,int want)
{
	if(z > want)
		return;
	if(now == n) {
		if(z == res && rec[0] != ' ')
			rc++;
		else if(z > res){
			pig = rec;
			res = z;
			rc = 1;
		}
		return;
	}
	rec.push_back(('0'+num[now]));
	dfs(now+1,z+last*10+num[now]-last,last*10+num[now],want);
	rec.insert(rec.end()-1,' ');
	dfs(now+1,z+num[now],num[now],want);
	rec.resize(rec.size()-2);
}
int main()
{
	int a;
	string b;
	while(cin >> a >> b )
	{
		if(a == 0 && b == "0")
			return 0;
		res = -1;
		rc = 0;
		pig = "";
		rec = "";
		n = b.size();
		for(int i = 0; i < n; i++)
			num[i] = b[i]-'0';
		dfs(0,0,0,a);
		if(res == -1)
			cout << "error" << endl;
		else if(rc > 1)
			cout << "rejected" << endl;
		else 
			cout << res << " " << pig << endl;
	}

	return 0;
}