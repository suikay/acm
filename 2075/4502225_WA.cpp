#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct Cable {
	int u;
	int v;
	float len;
	bool operator() (Cable a,Cable b) {
		return (a.len < b.len);
	}
}Cable;
Cable cable[250000];
typedef struct Name {
	char name[21];
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
	if(parent[x] > 0) {
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
	float sum;
	int n,m;
	Name *position;
	char s1[21],s2[21];
	float lenght;
	scanf("%f",&sum);
	scanf("%d\n",&n);
	memset(parent,-1,n * sizeof(int));
	for(int i = 0; i < n; i++) 
		scanf("%s\n",name[i].name);
	sort(name,name + n,Name());
	for(int i = 0; i < n; i++)
		name[i].id = i;
	scanf("%d",&m);
	for(int i = 0; i < m; i++) {
		scanf("%s %s %f",s1,s2,&lenght);
		position = (Name*)bsearch(s1,name,n,sizeof(Name),compare);
		cable[i].u = position - name;
		position = (Name*)bsearch(s2,name,n,sizeof(Name),compare);
		cable[i].v = position - name;
		cable[i].len = lenght;
	}
	sort(cable,cable+m,Cable());
	int count = 0,j = 0;
	float needLen = 0.0;
	while(true) {
		if(count == (n - 1) || (sum < needLen))
			break;
		if(Find(cable[j].u) != Find(cable[j].v)) {
			Union(cable[j].u,cable[j].v);
			needLen += cable[j].len;
			count++;
			j++;
		}
		else
			j++;
	}
	if( needLen > (sum + 10e-3))
		printf("Not enough cable\n");
	else
		if(needLen <= (sum + 10e-3) )
			printf("Need %.1f miles of cable",needLen);
	return 0;
}