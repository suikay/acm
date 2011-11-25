#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,ori_st[65],st_cnt,len_sum,st[65];
bool use[65];
bool dfs(int now,int which)
{
	if(now == n-1)
		return true;
	if(st[now] == 0) 
	{
		now++;
		for(int i = 0; i < st_cnt; i++) 
			if(!use[i] ) {
				st[now] -= ori_st[i];
				use[i] = true;
				if(dfs(now,i+1))
					return true;
				else {
					use[i] = false;
					st[now] += ori_st[i];
					return false;
				}
			}
		return true;
	}
	else 
	{
		if(st[now] < ori_st[st_cnt-1])
			return false;
		for(int i = which; i < st_cnt; i++) {
			if(st[now] >= ori_st[i] && !use[i])
			{
				st[now] -= ori_st[i];
				use[i] = true;
				if(dfs(now,i+1))
					return true;
				else {
					use[i] = false;
					st[now] += ori_st[i];
				}
			}
		}
	}
	return false;
}
int main()
{
	while(true)
	{
		memset(use,false,sizeof(use));
		len_sum = 0;
		cin >> st_cnt;
		if(st_cnt == 0)
			return 0;
		for(int i = 0; i < st_cnt; i++) {
			cin >> ori_st[i];
			len_sum += ori_st[i];
		}
		sort(ori_st,ori_st+st_cnt);
		reverse(ori_st,ori_st+st_cnt);
		for(int i = ori_st[0]; i < min(len_sum,50);  i++)
		{
			if(len_sum % i)
				continue;
			n = len_sum/i;
			for(int j = n-1; j >=0; j--)
				st[j] = i;
			if(dfs(0,0)) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
	