#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
string sts[1000];
int stm[1000];
bool v[210];
string bfs(int n) {
	string s;
	int mod;
	if(n == 1)
		return "1";
	memset(v,false,sizeof(v));
	int top,end;
	top = end = 0;
	sts[end] = "1";
	stm[end++] = 1;
	v[1] = true;
	while(top < end)
	{
		s = sts[top];
		mod = stm[top++];
		if(!v[(mod*10)%n]) {
			sts[end] = s+"0";
			stm[end] = mod*10%n;
			v[stm[end]] = true;
			if(!stm[end])
				return sts[end];
			end++;
		}
		if(!v[(mod*10+1)%n]) {
			sts[end] = s+"1";
			stm[end] = (mod*10+1)%n;
			v[stm[end]] = true;
			if(!stm[end])
				return sts[end];
			end++;
		}
	}
	return 0;
}

int main()
{
	int n;
	while(cin >> n && n)
		cout << bfs(n) << endl;

	return 0;
}