#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
vector<string> x;
int now[100];
bool v[100];
int main()
{
	int k,n,a,b,op;
	string tmp;
	scanf("%d",&k);
	while(k--)
	{
		memset(now,0,sizeof(now));
		memset(v,false,sizeof(v));
		scanf("%d%d",&n,&op);
		x.resize(0);
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			x.push_back(tmp);
		}
		for(int i = 0; i < op; i++) {
			scanf("%d%d",&a,&b);
			if(a > n || b > n)
				continue;
			now[b] = a;
			v[a] = true;
		}
		for(int i = 1; i <= n; i++)
			if(!v[i]) {
				for(int j = 1; j <= n; j++) 
					if(now[j] == 0) {
						now[j] = i;
						break;
					}
			}
		for(int i = 1; i <= n; i++)
			cout << x[now[i]-1] << " " ;
		cout << endl;
	}

	return 0;
}
/*
3 2
foo bar baz
3 1
1 3
*/