#include <stdio.h>
int FindDad(int *parent,int b)
{
	int a(b);
	// 找出最高的祖宗
	while( parent[a] != a)
		a = parent[a];
	// 对集合进行压缩
	int c;
	while(parent[b] != a) {
		c = parent[b];
		parent[b] = a;
		b = c;
	}
	return a;
}

void MergeSet(int *parent,int a,int b)
{
	int t1 = FindDad(parent,a);
	int t2 = FindDad(parent,b);
	if( t1 > t2) 
		parent[t2] = t1;
	else
		parent[t1] = t2;
}

int main()
{
	int parent[50005];
	int m, n;
	int count,time = 1;
	int t1,t2;
	scanf("%d%d",&n,&m);
	while( n) {
		count = 0;
		for( int i = 1; i <= n; i++)
			parent[i] = i;
		for( int i = 0; i < m; i++) {
			scanf("%d%d",&t1,&t2);
			MergeSet(parent,t1,t2);
		}
		for( int i =1; i <= n; i++)
			if( parent[i] == i)
				count ++;
		printf("Case %d: %d\n",time++,count);
		scanf("%d%d",&n,&m);
	}
	return 0;
}