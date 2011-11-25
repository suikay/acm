#include <stdio.h>
int FindParent(int *parent,int a)
{
	while( parent[a] != a)
		a = parent[a];
	return a;
}
void MergeSet(int *parent,int a, int b)
{
	int t1 = FindParent(parent,a);
	int t2 = FindParent(parent,b);
	if( t1 < t2)
		parent[t2] = t1;
	else
		parent[t1] = t2;
}
int main()
{
	int parent[30001];
	int m,n,time;
	int t1,t2;
	int count;
	scanf("%d%d",&n,&m);
	while(n) {
		count = 0;
		for( int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d%d",&time,&t1);
			for( int j = 1; j < time; j++) {
				scanf("%d",&t2);
				MergeSet(parent,t1,t2);
				t1 = t2;
			}
		}
		for( int i = 0; i < n; i++)
			if(!FindParent(parent,i)) 
				count++;
		printf("%d\n",count);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
