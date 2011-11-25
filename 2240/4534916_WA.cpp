#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char name[31][30];
int n;
int name_compare(void const *a,void const *b)
{
	return strcmp((char*)a,(char*)b);
}
int find(char* a)
{
	return (((char*)bsearch(a,name,n,sizeof(char) * 30,name_compare)) - *name)/30;
}
typedef struct {
	int w;
	int v;
	double weight;
} Edge;
Edge edge[1000];
double d[31];
bool BF(int path)
{
	for(int i = 0; i < n; i++)
		d[i] = 0.0;
	d[0] = 1.0;
	for(int i = 1; i < n; i++)
		for(int j = 0 ; j < path; j++)
			if(d[edge[j].w]*edge[j].weight>d[edge[j].v])
				d[edge[j].v] = d[edge[j].w]*edge[j].weight;
	for(int j = 0; j < path; j++)
		if(d[edge[j].w]*edge[j].weight>d[edge[j].v])
			return false;
	return true;
}
int main()
{
	int time = 1,m;
	double rate;
	char ci[30],cj[30];
	while((cin >> n) && n) 
	{
		for(int i = 0; i < n; i++)
			cin >> name[i];
		cin >> m;
		qsort(*name,n,30 * sizeof(char),name_compare);
		for(int i = 0; i < m; i++) {
			cin >> ci >> rate >> cj;
			edge[i].w = find(ci);
			edge[i].v = find(cj);
			edge[i].weight = rate;
		}
		BF(m);
		if(d[0] > 1.0)
			cout << "Case " << time++ << ": Yes\n";
		else
			cout << "Case " << time++ << ": No\n";
	}
	return 0;
}