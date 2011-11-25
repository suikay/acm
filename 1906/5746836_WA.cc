#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<string> t;
const long long ten = 10e17;
void init()
{
	char str[50];
	long long res,r;
	res = 1;
	r = 0;
	t.push_back("1");
	for(int i = 1; i < 70; i++) {
		r *= 3;
		res *= 3;
		if(res > ten) {
			r += res / ten;
			res %= ten;
		}
		if(r)
			sprintf(str,"%lld%.017lld",r,res);
		else 
			sprintf(str,"%lld",res);
		t.push_back(string(str));
	}
}
int main()
{
	vector<string> res;
	unsigned long long tmp;
	int now;
	init();
	while(true)
	{
		res.resize(0);
		cin >> tmp;
		if(!tmp)
			return 0;
		tmp--;
		now = 0;
		while(tmp) {
			if(tmp & 1) 
				res.push_back(t[now]);
			now++;
			tmp >>= 1;
		}
		if(res.size()) {
			printf("{ %s",res[0].c_str());
			for(int i = 1; i < res.size(); i++)
				printf(", %s",res[i].c_str());
			printf(" }\n");
		}else 
			printf("{ }\n");
	}

	return 0;
}