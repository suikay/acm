#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;
map<int,int> ch;
int f(char x[])
{
	static int sz,res;
	sz = strlen(x);
	res = 1 << (25-(x[0]-'a'));
	if(sz >= 6)
		return 0;
	res |= (6-sz) << 26;
	for(int i = 1; i < sz; i++) {
		res |= 1 << (25-(x[i]-'a'));
		if(x[i] <= x[i-1])
			return 0;
	}
	return res;
}
int main()
{
	int x(0);
	for(int i = 0; i < 26; i++) {
		x |= 1 << i;
		ch[x|(5 << 26)] = 0;
		for(int j = i+1; j < 26; j++) {
			x |= 1 << j;
			ch[x|(4 << 26)] = 0;
			for(int k = j+1; k < 26; k++) {
				x |= 1 << k;
				ch[x|(3 << 26)] = 0;
				for(int l = k+1; l < 26; l++) {
					x |= 1 << l;
					ch[x|(2 << 26)] = 0;
					for(int m = l+1; m < 26; m++) {
						x |= 1 << m;
						ch[x|(1 << 26)] = 0;
						x ^= 1 << m;
					}
					x ^= 1 << l;
				}
				x ^= 1 << k;
			}
			x ^= 1 << j;
		}
		x ^= 1 << i;
	}
	int now = 83681;
	for(map<int,int>::iterator itr = ch.begin(),en = ch.end(); itr != en; itr++) 
		itr->second = now--;
	char pp[1000];
	while(gets(pp))
		printf("%d\n",ch[f(pp)]);
	return 0;
}