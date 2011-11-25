#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
int a,b,pn;
int arr[1000050],res[1000000];
multiset<int> x;
inline void put(int x){
	if(x< 0){
		putchar('-');
		x = -x;
	}
	if(x == 0){
		putchar('0');
		return;
	}
	char s[20];
	int bas = 0;
	for(;x;x/=10)s[bas++] = x%10+'0';
	for(;bas--;)putchar(s[bas]);
	return;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i = 0; i < b-1; i++) {
		scanf("%d",arr+i);
		x.insert(arr[i]);
	}
	for(int i = b-1; i < a; i++) {
		scanf("%d",arr+i);
		x.insert(arr[i]);
		put(*(x.begin()));
		putchar(' ');
		res[pn++] = *((x.rbegin()));
		x.erase(arr[i-b+1]);
	}
	puts("");
	for(int i = 0; i < pn; i++) {
		put(res[i]);
		putchar(' ');
	}
	puts("");

	return 0;
}