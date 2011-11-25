#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 30
int parent[N],son[N];
int fp(int x)	{
	while(parent[x]!=x)
		x = parent[x];
	return x;
}
int fs(int x)	{
	while(son[x]!=x)
		x = son[x];
	return x;
}
void clear(int x)	{
	if(son[x]==x)
		return;
	x = son[x];
	son[parent[x]] = parent[x];
	int tmp;
	while(x != son[x])	{
		son[parent[x]] = parent[x];
		tmp = son[x];
		son[x] = x;
		x = tmp;
	}
	parent[x] = x;
}
void connect(int p,int s)	{
	if(son[p]!=p)
		parent[son[p]] = son[p];
	son[p] = s;
	if(parent[s]!=s)
		son[parent[s]] = parent[s];
	parent[s] = p;
}
int main()
{
	string str1,str2;
	int a,b,n;
	for(int i = 0; i < N; i++)	
		parent[i] = son[i] = i;
	scanf("%d",&n);
	while(true){
		cin >> str1 ;
		if(str1 == "quit")
			break;
		cin >> a >> str2 >> b;
		if(a==b || fp(a)==fp(b))
			continue;
		if(str2=="onto")
			clear(b);
		if(str1=="move")
			clear(a);
		connect(fs(b),a);
	}
	for(int i = 0; i < n; i++)
		if(parent[i]==i)	{
			cout << i << ":";
			int tmp = i;
			while(true)	{
				cout << " " << tmp;
				if(tmp==son[tmp])
					break;
				tmp = son[tmp];
			}
			cout << endl;
		}
		else
			cout << i << ":" << endl;
	return 0;
}