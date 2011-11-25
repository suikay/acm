#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
struct Mut
{
	int s,t;
	bool operator<(const Mut &mm) const{
		return s < mm.s;
	}
};
Mut m[100010];
int main()
{
	int n,l,t,cnt,last;
	scanf("%d%d",&n,&l);
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&m[i].s,&t);
		m[i].t = t-1;
	}
	sort(m,m+n);
	last = -1;
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(last >= m[i].t)
			continue;
		if(last >= m[i].s)
			m[i].s = last + 1;
		t = (m[i].t - m[i].s + l) / l;
		cnt += t;
		last = m[i].s + t*l - 1;
		//cout << t << " " << last << endl;
	}
	printf("%d\n",cnt);

	return 0;
}
