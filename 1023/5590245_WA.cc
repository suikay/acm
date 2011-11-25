#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	unsigned long long k,clean,res;
	long long kk,one(1);
	int n;
	bool success;
	char str[10000];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		success = true;
		clean = 0;
		cin >> n;
		cin >> str;
		cin >> kk;
		if(kk < 0) {
			if(kk == one << 63)
				k = one << 63;
			else {
				kk = -kk;
				k = kk;
			}
			reverse(str,str+n);
			for(int i = 0; i < n; i++)
				if(str[i] == 'n')
					clean |= (one << i);
		} else {
			k = kk;
			reverse(str,str+n);
			for(int i = 0; i < n; i++) {
//				cout << "STR " << str[i]  << endl;
				if(str[i] == 'p') 
					clean |= (one << i);
			}
		}
		res = k;
		if(clean < kk)
			success = false;
		for(int i = 0; i < 64; i++)
			if((k & (one << i)) && (clean & (one<<i))==0) 
				if((k & (one << (i+1))) || (clean & (one << (i+1)))==0)
					success = false;
				else 
					res |= (one << (i+1));
//		cout << res << endl;
		if(!success)
			cout << "Impossible" << endl;
		else {
			int j;
			for(j = 63; j >= 0; j--)
				if(res & (one << j))
					break;
			for(; j >= 0; j--)
				if(res & (one << j))
					putchar('1');
				else
					putchar('0');
			puts("");
		}
	}

	return 0;
}