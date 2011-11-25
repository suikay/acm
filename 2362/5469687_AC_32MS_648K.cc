#include<iostream>
#include<string.h>
using namespace std;
int len[25],want_len,N;
bool v[25],valid;
void dfs(int,int,int);
int main()
{
	int c,sum;
	cin >> c;
	while(c--) 
	{
		cin >> N; 
		sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> len[i];
			sum += len[i];
		}
		valid = false;
		if(sum % 4)
			cout << "no" << endl;
		else {
			want_len = sum / 4;
			int i;
			for(i = 0; i < N; i++)
				if(want_len < len[i]) {
					cout << "no" << endl;
					break;
				}
			if(i == N) {
				memset(v,false,sizeof(v));
				dfs(-1,0,0);
				if(valid)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}
		}
	}
	return 0;
}
void dfs(int st_num,int last_len,int last_st)
{
	if(last_len < 0 || valid)
		return;
	if(last_len == 0)
	{
		if(st_num == 3) {
			valid = true;
			return;
		}
		else {
			for(int i = 0; i < N; i++)
				if(!v[i]) {
					v[i] = true;
					dfs(st_num+1,want_len - len[i],i);
					v[i] = false;
					break;
				}
		}
		return;
	}
	for(int i = last_st; i < N; i++) 
		if(last_len >= len[i] && !v[i]) {
			v[i] = true;
			dfs(st_num,last_len-len[i],i);
			v[i] = false;
		}
}