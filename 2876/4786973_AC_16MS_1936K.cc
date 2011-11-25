#include<string>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	string x[13];
	x[0] = "-";
	for(int i = 1; i < 13; i++)
	{
		string tmp(x[i-1].size(),' ');
		x[i] = x[i-1]+tmp+x[i-1];
	}
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%s\n",x[n].c_str());
	return 0;
}