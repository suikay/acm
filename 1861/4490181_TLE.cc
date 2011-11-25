#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
	int lenght;
} pipeType;
pipeType pipe[15005];
int parent[1005];
int compare(const void* a,const void* b){
	return ((pipeType*)a)->lenght - ((pipeType*)b)->lenght;
}
/*
void swap(int x, int y)
{
	int t1;
	t1 = pipe[x].x;pipe[x].x = pipe[y].x; pipe[y].x = t1;
	t1 = pipe[x].y;pipe[x].y = pipe[y].y; pipe[y].y = t1;
	t1 = pipe[x].lenght;pipe[x].lenght = pipe[y].lenght; pipe[y].lenght = t1;
}
*/
int FindParent(int x)
{
	if( parent[x] != x) 
		parent[x] = FindParent(parent[x]);
	return parent[x];
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
	int t1,t2, i;
	int max, sum = 0;
	scanf("%d%d",&n,&d);
	for( i = 1; i <= n; i++)
		parent[i] = i;
	for( i = 0; i < d; i++)
		scanf("%d%d%d",&pipe[i].x, &pipe[i].y, &pipe[i].lenght);
	for( i = 0; i < d; i++)
		for(int  j = i + 1; j < d; j++)
			if( pipe[i].lenght > pipe[j].lenght) {
				int t1;
				t1 = pipe[i].x;pipe[i].x = pipe[j].x; pipe[j].x = t1;
				t1 = pipe[i].y;pipe[i].y = pipe[j].y; pipe[j].y = t1;
				t1 = pipe[i].lenght;pipe[i].lenght = pipe[j].lenght; pipe[j].lenght = t1;
			}
	//pipeType *pp = pipe + d + 1;
	//sort(pipe,pp);
	//	qsort(pipe,d,sizeof(pipeType),compare);
	for( i = 0; i < d && count < (n - 1); i++) {
		t1 = FindParent(pipe[i].x);
		t2 = FindParent(pipe[i].y);
		if( t1 != t2)  {
			count++;
			MergeSet(t1,t2);
		}
		max = pipe[i].lenght;
	}
	printf("%d\n%d\n",max,i);
	for(int j = 0; j < i ; j++)
		if(pipe[j].x != pipe[j].y)
			printf("%d %d\n",pipe[j].x,pipe[j].y);
}
