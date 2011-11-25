#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool found;
int len,k,mm[110],kk;
char now[110],res_str[110];
void dfs(int place,int last2change,int mod)
{
//	cout << now << "  " << last2change << " " << mod << endl;
	char ori_ch;
	int pp;
	if(last2change == 0) {
		if(mod % k == 0)
			if(now[0] != '0' && (strcmp(now,res_str) < 0)) {
				memcpy(res_str,now,sizeof(now));
				found = true;
		}
		return;
	}
	if(place >= len)
		return;
	ori_ch = now[place];
	for(int i = '0'; i <= '9'; i++) {
		pp = (mm[place]*(i-ori_ch)+kk)%k;
		if(ori_ch == i || pp == 0)
			continue;
		now[place] = i;
		dfs(place+1,last2change-1,(mod+pp)%k);
	}
	now[place] = ori_ch;
	dfs(place+1,last2change,mod);
}

int main()
{
	int ori_mod;
	while(cin >> now >> k)
	{
		kk = 100*k;
		len = strlen(now);
		mm[0] = 1;
//		cout << 10 % 1000 << endl;
		for(int i = 1; i < len; i++) 
			mm[i] = (10 * mm[i-1]) % k;
		reverse(mm,mm+len);
//		cout << " MM " ;
//		for(int i = 0; i < len; i++)
//			cout << mm[i] << " ";
//		cout << endl;
		ori_mod = 0;
		for(int i = 0; i < len; i++)
			ori_mod = (ori_mod + mm[i] * (now[i] - '0')) % k;
//		cout << "ORI_MOD " << ori_mod << endl;
		if(ori_mod == 0)
		{
			cout << now << endl;
			continue;
		}
		found = false;
		for(int i = 0; i < len; i++)
			res_str[i] = '9';
		res_str[len] = '\0';
		for(int i = 1;!found && i < 5; i ++)
			dfs(0,i,ori_mod);
		cout << res_str << endl;
	}
	return 0;
}
//9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999