#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define mm(a,b) ((a)>(b))?(b):(a)
using namespace std;
char tmp[100],arr[1010][9],cnt[1010][26],now[26],*t;
int main()
{
	int n,res,_free,pp;
	while(gets(tmp))
	{
		res = 0;
		_free = 0;
		if(tmp[0] == '0')
			return 0;
		memset(cnt,0,sizeof(cnt));
		memset(now,0,sizeof(now));
		sscanf(tmp,"%d",&n);
		for(int i = 0; i < n; i++) {
			gets(arr[i]);
			t = arr[i];
			for(int j = strlen(t)-1; j >= 0; j--)
				cnt[i][t[j]-'A']++;
		}
		gets(tmp);
		sort(tmp,tmp+strlen(tmp));
		for(int i = strlen(tmp)-1; i >= 0; i--)
			if(tmp[i] == '_') 
				_free++;
			else
				now[tmp[i]-'A']++;
		for(int i = 0; i < n; i++) {
			pp = 0;
			for(int j = 0; j < 26; j++) 
				pp += mm(now[j],cnt[i][j]);
			if((pp+_free) >= strlen(arr[i])) {
				res++;
			}
		}
		printf("%d\n",res);
	}


	return 0;
}