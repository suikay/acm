#include <stdio.h>
#include <memory.h>
int parent[2001];
int aparent[2001];
int FindParent(int a) {
	while( a != parent[a])
		a = parent[a];
	return a;
}
int MergeSet(int a,int b)
{
	if( a > b) 
		return(parent[b] = a);
	else
		return(parent[a] = b);
}
int MergeOppisiteSet(int a,int b)
{
	bool flag = true;
	int t1 = FindParent(a);
	int t2 = FindParent(b);
	if( t1 == t2 || (aparent[t1] && aparent[t2] && aparent[t1] == aparent[t2]))
		return 0;
	if( aparent[t1] != t2)
		aparent[t1] = MergeSet(aparent[t1],t2);
	if( aparent[t2] != t1)
		aparent[t2] = MergeSet(aparent[t2],t1);
	return 1;
}
int main()
{
	int time,n,d;
	int x,y;
	scanf("%d",&time);
	for( int i = 1; i <= time; i++) {
		bool flag = true;
		scanf("%d%d",&n,&d);
		memset(aparent,0,(n + 1) * sizeof( int ));
		for( int j = 1; j <= n; j++)
			parent[j] =  j;
		for( int j = 0 ; j < d; j++) {
			scanf("%d%d",&x,&y);
			if(!MergeOppisiteSet(x,y))
				flag = false;
		}
		if( flag )
			printf("Scenario #%d:\nNo suspicious bugs found!\n\n",i);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n\n",i);
	}
}
