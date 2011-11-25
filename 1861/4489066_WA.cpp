#include <stdio.h>
#include <stdlib.h>
typedef struct pipeType{
	int x;
	int y;
	int lenght;
	bool get;
}pipeType;
pipeType pipe[1005];
int parent[1005];
int compare(const void* a,const void* b)
{
	if (((pipeType *)a)->lenght - ((pipeType*) b)->lenght)
		return (((pipeType *)a)->lenght - ((pipeType*) b)->lenght);
	else
		return 1;
}
int FindParent(int x)
{
	while( parent[x] != x)
		x = parent[x];
	return x;
}
void MergeSet(int x,int y)
{
	if( x > y)
		parent[y] = x;
	else
		parent[x] = y;
}
int main()
{
	int n,d,count = 0;
	int t1,t2;
	int max, sum = 0;
	scanf("%d%d",&n,&d);
	for( int i = 1; i <= n; i++)
		parent[i] = i;
	for( int i = 0; i < d; i++) {
		scanf("%d%d%d",&pipe[i].x, &pipe[i].y, &pipe[i].lenght);
		pipe[i].get = false;
	}
	qsort(pipe,d,sizeof(pipeType),compare);
	for( int i = 0; i < d && count < (n - 1); i++) {
		t1 = FindParent(pipe[i].x);
		t2 = FindParent(pipe[i].y);
		if( t1 != t2) 
			count++;
		MergeSet(t1,t2);
		max = pipe[i].lenght;
		sum += max;
		pipe[i].get = true;
	}
	printf("%d\n%d\n",max,sum);
	for( int i = 0; i < n; i++)
		if(pipe[i].get)
			printf("%d %d\n",pipe[i].x,pipe[i].y);
}
