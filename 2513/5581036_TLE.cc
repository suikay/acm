#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 500050;
struct String
{
	char name[11];
	friend bool operator<(const String &a,const String &b) {
		return strcmp(a.name,b.name) < 0;
	}
	friend bool operator==(const String &a,const String &b) {
		return strcmp(a.name,b.name) == 0;
	}
};
map<String,int> c2i;
int cnt[N],v[N];
int main()
{
	String a,b;
	int pn = 0,n(0),aa,bb;
//	freopen("2513.in","r",stdin);
	while(scanf("%s%s",a.name,b.name) != EOF)
	{
		getchar();
		if(c2i.count(a)==0)
			aa = c2i[a] = pn++;
		else 
			aa = c2i[a];
		if(c2i.count(b)==0)
			bb = c2i[b] = pn++;
		else
			bb = c2i[b];
		if(aa == bb)
			v[aa] = true;
		else {
			cnt[aa]++;
			cnt[bb]++;
		}
		n++;
	}
	if(pn > n+1) {
		cout << "Impossible" << endl;
		return 0;
	}
	int odd(0),pp(0);
	if(pn == 1) {
		cout << "Possible" << endl;
		return 0;
	}
	for(int i = 0; i < pn; i++) {
		if(v[i] && cnt[i] == 0) {
			cout << "Impossible" << endl;
			return 0;
		}
		if(cnt[i] % 2)
			odd++;
	}
	if(odd != 0 && odd != 2)
		cout << "Impossible" << endl;
	else
		cout << "Possible" << endl;

	return 0;
}