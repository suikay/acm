#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool found,v[10000];
int len,k,mm[110],kk;
char now[110],res_str[110];
void dfs(int place,int last2change,int mod)
{
//	cout << "dfs " << now << " " << mod << endl;
	char ori_ch;
	int pp,i;
	if(mod == 0) {
//		cout << "HELLO " << now << endl;
			if(now[0] != '0' && (strcmp(now,res_str) < 0)) {
				memcpy(res_str,now,sizeof(now));
				found = true;
		}
		return;
	}
	v[mod] = true;
	if(last2change == 0) {
		v[mod] = false;
		return;
	}
	if(place >= len)
		return;
	ori_ch = now[place];
	if(place == 0)
		i = '0';
	else i = '1';
	for(; i <= '9'; i++) {
		pp = (mod + mm[place]*(i-ori_ch)+kk)%k;
		if(ori_ch == i || v[pp])
			continue;
		now[place] = i;
		dfs(place+1,last2change-1,pp);
	}
	now[place] = ori_ch;
	dfs(place+1,last2change,mod);
	v[mod] = false;
}

int main()
{
	int ori_mod;
	while(cin >> now >> k)
	{
		kk = 10000*k;
		len = strlen(now);
		mm[0] = 1;
		for(int i = 1; i < len; i++) 
			mm[i] = (10 * mm[i-1]) % k;
		reverse(mm,mm+len);
//		for(int i = 0; i < len; i++)
//			cout << mm[i] << " ";
//		cout << endl;
		ori_mod = 0;
		for(int i = 0; i < len; i++)
			ori_mod = (ori_mod + mm[i] * (now[i] - '0')) % k;
		if(ori_mod == 0)
		{
			cout << now << endl;
			continue;
		}
		found = false;
		for(int i = 0; i < len; i++)
			res_str[i] = '9';
		res_str[len] = '\0';
		for(int i = 1;!found && i < 5; i ++) {
			memset(v,false,sizeof(v));
			dfs(0,i,ori_mod);
		}
		cout << res_str << endl;
	}
	return 0;
}
//9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999