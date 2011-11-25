#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool v[1000];
int main()
{
	string tmp;
	int n,now,res;
	while(true) 
	{
		memset(v,false,sizeof(v));
		now = res = 0;
		cin >> n;
		if(n == 0)
			return 0;
		cin >> tmp;
		for(int i = 0,sz = tmp.size(); i < sz; i++) 
			if(v[tmp[i]]) {
				v[tmp[i]] = false;
				now--;
			}
			else {
				now++;
				v[tmp[i]] = true;
				if(now > n)
					res++;
			}
		if(!res)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n",res);
	}

	return 0;
}