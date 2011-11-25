#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
#define N 65
int many[N],in[N];
int want,MAX;
bool f(int last,int max)
{
	int i;
	if(last==0) {
		for(i = MAX; i > 0; i--)
			if(many[i])
				break;
		if(!i)
			return true;
		many[i]--;
		if(f(want-i,MAX))
			return true;
		many[i]++;
	}
	else
		for(i = last>max?max:last; i > 0; i--) {
			if(!many[i])
				continue;
			many[i]--;
			if(f(last-i,i))
				return true;
			many[i]++;
			if(i == last)
				break;
		}
	return false;
}
int main()
{
	int n,temp;
	while(cin >> n && n) {
		MAX = 0;
		for(int i = 0 ;i < n; i++) {
			cin >> temp;
			if(temp > MAX)
				MAX = temp;
			many[temp]++;
		}
		want = MAX;
		while(true) {
			if(f(0,MAX))
				break;
			want++;
		}
		cout << want << endl;
	}
	return 0;
}
	 