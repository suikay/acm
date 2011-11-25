#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct Cable {
	int u;
	int v;
	double len;
	bool operator() (Cable a,Cable b) {
		return (a.len < b.len);
	}
}Cable;
Cable cable[250000];
typedef struct Name {
	char name[25];
	int id;
	bool operator() (Name a,Name b) {
		if(strcmp(a.name,b.name) < 0)
			return true;
		else
			return false;
	}
}Name;
Name name[5000];
int parent[5000];
int compare(const void* a,const void* b) 
{
	return strcmp((char *)a,((Name*)b)->name);
}
int Find(int x)
{
	if(parent[x] >= 0) {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
	else
		return x;
}
void Union(int x,int y)
{
	x = Find(x);
	y = Find(y);
	if( x == y)
		return ;
	if( parent[x] < parent[y])
		parent[y] = x;
	else
		if(parent[x] == parent[y]) {
			parent[y] = x;
			parent[x]--;
		}
		else
			parent[y] = x;
}
int main()
{
	double sum;
	int n,m;
	Name *position;
	char s1[25],s2[25];
	double lenght;
	cin >> sum;
	cin >> n;
	memset(parent,-1,n * sizeof(int));
	for(int i = 0; i < n; i++) 
		cin >> name[i].name;
	sort(name,name + n,Name());
	for(int i = 0; i < n; i++)
		name[i].id = i;
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> s1 >> s2 >> lenght;
		position = (Name*)bsearch(s1,name,n,sizeof(Name),compare);
		cable[i].u = position - name;
		position = (Name*)bsearch(s2,name,n,sizeof(Name),compare);
		cable[i].v = position - name;
		cable[i].len = lenght;
	}
	sort(cable,cable+m,Cable());
	int count = 0,j = 0;
	double needLen = 0.0;
	while(true) {
		if(Find(cable[j].u) != Find(cable[j].v)) {
			Union(cable[j].u,cable[j].v);
			needLen += cable[j].len;
			count++;
			j++;
		}
		else
			j++;
		if(j == m)
			break;
	}
	if( needLen > (sum+10e-4))
		cout << "Not enough cable\n";
	else
		printf("Need %.1f miles of cable\n",needLen);
	return 0;
}