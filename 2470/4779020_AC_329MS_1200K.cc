#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;
bool equal(int*x,int*y,int n)
{
	for(int i = 1; i <= n; i++)
		if(x[i] != y[i])
			return false;
	return true;
}
int main()
{
	int p1[100010],p2[100010];
	int n,tmp;
	while(scanf("%d",&n) && n)
	{
		for(int i = 1; i <= n; i++){
			scanf("%d",&tmp);
			p1[i] = tmp;
			p2[tmp] = i;
		}
		if(equal(p1,p2,n))
			cout << "ambiguous" << endl;
		else
			cout << "not ambiguous" << endl;
	}
	return 0;
}