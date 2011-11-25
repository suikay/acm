#include<iostream>
#include<stdio.h>
#define SZ 1000
using namespace std;
void add(char* a,char* b,char* c)
{
	for(int i = 0; i < SZ; i++)
		c[i] = a[i] + b[i];
	for(int i = 0; i < SZ-1; i++){
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
}
int main()
{
	int n,left,tmp;
	char zp[1010][SZ],op[1010][SZ];
	memset(zp,0,sizeof(zp));
	memset(op,0,sizeof(op));
	zp[0][0] = 1;
	left = 0;
	for(int i = 2; i <= 1000; i++)	{
		add(zp[i-1],op[i-1],zp[i]);
		add(zp[i-1],op[i-1],op[i]);
		if(left == 0){
			left = 1;
			add(zp[i],zp[0],zp[i]);
		}
		else
			left = 0;
	}
	while(cin >> n)
	{
		int i = SZ-1;
		for(;i > 0 && zp[n][i] == 0;i--)
			;
		for(;i >= 0; i--)
			cout << (int)zp[n][i];
		cout << endl;
	}
	return 0;
}