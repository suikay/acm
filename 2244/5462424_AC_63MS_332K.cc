#include<stdio.h>
struct Edge {
	int num;
	int next;
};
Edge e[200];
bool check(int m,int n)
{
	for(int i = 0; i < m; i++) {
		e[i].num = i+1;
		e[i].next = i+1;
	}
	e[m-1].next = 1;
	int tmp(m-1);
	for(int i = 1; i < m-1; i++) {
		for(int j = 1; j < n; j++)
			tmp = e[tmp].next;
		if(e[tmp].next == 1)
			return false;
		e[tmp].next = e[e[tmp].next].next;
	}
	return true;
}
int main()
{
	int n; 
	while(scanf("%d",&n) && n)
		for(int i = 2;true; i++)
			if(check(n,i))
			{
				printf("%d\n",i);
				break;
			}
	return 0;
}

