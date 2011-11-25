#include <stdio.h>
#include <memory.h>
int parent[50005];
int eatParent[50005];
int eatedParent[50005];
int FindParent(int a)
{
	while(parent[a] != a )
		a = parent[a];
	return a;
}
int MergeSet(int a,int b)
{
	int t1 = FindParent(a);
	int t2 = FindParent(b);
	if(t1 < t2)
		return (parent[t1] = t2);
	else
		return (parent[t2] = t1);
}
int MergeSameSet(int a,int b)
{
	int t1 = FindParent(a);
	int t2 = FindParent(b);
	if( (eatParent[t1] && eatedParent[t2] && eatParent[t1] && eatedParent[t2]) || \
		(eatedParent[t1] && eatedParent[t2] && eatedParent[t1] == eatedParent[t2] ))
		return 0;
	if( t1 > t2) {
		parent[t2] = parent[t1];
		eatParent[t1] = MergeSet(eatParent[t1],eatParent[t2]);
		eatedParent[t1] = MergeSet(eatedParent[t1],eatedParent[t2]);
	}
	else { 
		parent[t1] = parent[t2];
		eatParent[t2] = MergeSet(eatParent[t1],eatParent[t2]);
		eatedParent[t2] = MergeSet(eatedParent[t1],eatedParent[t2]);
	}
	return 1;
}
int MergeOppisiteSet(int a ,int b)
{
	int t3;
	int t1 = FindParent(a);
	int t2 = FindParent(b);
	if( t1 == t2 || (eatParent[t1] && eatParent[t2] && eatParent[t1] == eatParent[t2]) || \
		(eatedParent[t1] && eatedParent[t2] && eatedParent[t1] == eatedParent[t2]) || \
		(eatParent[t1] && eatParent[t1] == t2) || (eatParent[t2] && eatParent[t2] == t1))
		return 0;
	t1 = MergeSet(eatParent[t2],t1);
	t2 = MergeSet(t2,eatedParent[t1]);
	t3 = MergeSet(eatParent[t1],eatedParent[t2]);
	eatParent[t1] = eatedParent[t2] = t3;
	eatParent[t2] = eatedParent[t3] = t1;
	eatParent[t3] = eatedParent[t1] = t2;
	return 1;
}
int main()
{
	int n, k, count = 0;
	int d,x,y;
	scanf("%d%d",&n,&k);
	for( int i = 1; i <= n; i++)
		parent[i] = i;
	memset(eatParent,0,(n + 1) * sizeof( int));
	memset(eatedParent,0,(n + 1) * sizeof( int));
	for( int i = 0; i < k ; i++) {
		scanf("%d%d%d",&d,&x,&y);
		if( x > n || y > n || ( d == 2 && x == y)) {
			count++;
			continue;
		}
		if( d == 1)  {
			if(!MergeSameSet(x,y))
				count++;
		}
		else
			if(!MergeOppisiteSet(x,y))
				count++;
	}
	printf("%d\n",count);
}