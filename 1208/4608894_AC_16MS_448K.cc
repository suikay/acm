#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 30
int down[N],up[N];
int fd(int x)	{
	while(down[x]!=x)
		x = down[x];
	return x;
}
int fu(int x)	{
	while(up[x]!=x)
		x = up[x];
	return x;
}
void clear(int x)	{
	if(up[x]==x)
		return;
	x = up[x];
	up[down[x]] = down[x];
	int tmp;
	while(x != up[x])	{
		up[down[x]] = down[x];
		tmp = up[x];
		up[x] = x;
		down[x] = x;
		x = tmp;
	}
	down[x] = x;
}
void connect(int below,int upon)	{
	//if(up[below]!=below)
		//down[up[below]] = up[below];
	up[below] = upon;
	if(down[upon]!=upon)
		up[down[upon]] = down[upon];
	down[upon] = below;
}
int main()
{
	string str1,str2;
	int a,b,n;
	for(int i = 0; i < N; i++)	
		down[i] = up[i] = i;
	scanf("%d",&n);
	while(true){
		cin >> str1 ;
		if(str1 == "quit")
			break;
		cin >> a >> str2 >> b;
		if(fd(a)==fd(b))
			continue;
		if(str2=="onto")
			clear(b);
		if(str1=="move")
			clear(a);
		connect(fu(b),a);
	}
	for(int i = 0; i < n; i++)
		if(down[i]==i)	{
			cout << i << ":";
			int tmp = i;
			while(true)	{
				cout << " " << tmp;
				if(tmp==up[tmp])
					break;
				tmp = up[tmp];
			}
			cout << endl;
		}
		else
			cout << i << ":" << endl;
	return 0;
}