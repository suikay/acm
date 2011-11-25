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

using namespace std;
int main()
{
	int m,need,n,weekly,per;
	long long res(0);
	cin >> n >> weekly;
	m = 1000000;
	for(int i = 0; i < n; i++) {
		cin >> per >> need;
		if(per < m)
			m = per;
		res += m * need;
		m += weekly;
	}
	cout << res << endl;
	return 0;
}