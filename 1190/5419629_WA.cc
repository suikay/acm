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
int N,M,res;
bool dfs(int now,int R,int H,int V,int S)
{
	if(V > N)
		return false;
	if(now == M) {
		int s(0);
		//s = R*R;
		if(V == N)
			if(res > (s+S)) {
				res = S+s;
				return true;
			}
		return true;
	}
	for(int i = R+1;true; i++) {
		if(dfs(now+1,i,H+1,V+i*i*(H+1),S+2*i*(H+1)) == false)
			break;
		for(int j = H+2; true; j++)
			if(dfs(now+1,i,j,V+i*i*j,S+2*i*j) == false)
				break;
	}
	return false;
}
int main()
{
	cin >> N >> M;
	res = 99999999;
	dfs(0,0,0,0,0);
	if(res == 99999999)
		cout << 0 << endl;
	else
		cout << res << endl;
	return 0;
}