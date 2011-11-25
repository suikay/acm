#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Word
{
	char w[30];
	friend bool operator<(const Word &a,const Word &b) {
		return strcmp(a.w,b.w) < 0;
	}
};
map<Word,int> mwi;
int cnt[20010];
int main()
{
	int m,n;
	Word tmp;
	while(true)
	{
		mwi.clear();
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&m,&n);
		if(!m && !n)
			return 0;
		getchar();
		for(int i = 0; i < m; i++) {
			gets(tmp.w);
			mwi[tmp]++;
		}
		map<Word,int>::iterator itr;
		itr = mwi.begin();
		for(;itr != mwi.end(); itr++)
			cnt[itr->second]++;
		for(int i = 1; i <= m; i++)
			printf("%d\n",cnt[i]);
	}

	return 0;
}