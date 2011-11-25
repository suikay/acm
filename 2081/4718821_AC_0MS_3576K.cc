#include<iostream>
#include<stdio.h>
using namespace std;
bool in[10000000];
int d[500010];
int main()
{
		int tmp = d[0] = 0;
		for(int i = 1; i <= 500000; i ++)	{
			if(tmp > i && !in[tmp-i])
				tmp -= i;
			else 
				tmp += i;
			in[tmp] = true;
			d[i] = tmp;
		}
	int n;
	while(cin >> n && n > -1)	{
	cout << d[n] << endl;
	}
	return 0;
}