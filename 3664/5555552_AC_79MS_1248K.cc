#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Cow
{
	int a,b,num;
	bool operator()(const Cow &x,const Cow &y) {
		return x.a > y.a;
	}
	bool operator<(const Cow &y) {
		return this->b < y.b;
	}
};
Cow cow[51000];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++) {
		scanf("%d%d",&(cow[i].a),&(cow[i].b));
		cow[i].num = i+1;
	}
	sort(cow,cow+n,Cow());
	make_heap(cow,cow+k);
	cout << cow[0].num << endl;

	return 0;
}